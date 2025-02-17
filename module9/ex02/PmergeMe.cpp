/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:58 by clundber          #+#    #+#             */
/*   Updated: 2025/02/17 22:26:47 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

	PmergeMe::PmergeMe(){}
	PmergeMe::~PmergeMe(){}
	
	PmergeMe::PmergeMe(PmergeMe& other)
	{
		*this = other;
	}

	PmergeMe& PmergeMe::operator=(PmergeMe& other)
	{
		if (this != &other)
		{
			this->list = other.list;
			this->vector = other.vector;
			this->before = other.before;
		}
		return (*this);
	}

	bool PmergeMe::duplicateCheck()
	{
		std::unordered_set<int> check;
		for (auto it : before)
		{
			if (check.count(it))
				return(true);
			check.insert(it);
		}
		return false;
	}

	void PmergeMe::argVal(char* argv[])
	{
		std::regex numReg(R"(^-?\d+$)");
		for (int i = 1; argv[i]; i++)
		{
			int temp = std::stoi(argv[i]);
			if (temp < 0)
				throw std::invalid_argument("Error");
			if (i > 3100)
				throw std::invalid_argument("Error");
		}
		for (int i = 1; argv[i]; i++)
		{
			if (!std::regex_match(argv[i], numReg))
				throw std::invalid_argument("Error");
			before.push_back(std::stoi(argv[i]));
		}
		if (duplicateCheck())
			throw std::invalid_argument("Error");
	}

	void PmergeMe::chunkVec(std::vector<int>& vec, std::vector<std::vector<int>>& temp, int chunkSize)
	{
		int pair = 0;
		int nbr = 1;
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (pair >= (int)temp.size() -1)
				temp.emplace_back();
			temp[pair].emplace_back(vec[i]);
			if (nbr % chunkSize == 0)
				pair++;
			nbr++;
		}
		if (temp.size() > 1 && temp.back().empty())
			temp.pop_back();
	}

	bool compareLast(const std::vector<int>& a, const std::vector<int>& b)
	{
		return a.back() < b.back();
	}

	int jacobsthal(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    long a = 1;
    long b = 1;

    for (int i = 2; i <= n; ++i) {
        long next = b + 2 * a;
        a = b;
        b = next;
    }

    return b;
}

void PmergeMe::sortVector(std::vector<int>& vec, int chunkSize)
{
	if (chunkSize > (int)vec.size() / 2)
		return ;
	std::vector<std::vector<int>> temp;
	// //create the chunks as sub vectors of temp
	chunkVec(vec, temp, chunkSize);
	//sort the chunks with its neighbour
	for (size_t i = 0; i < temp.size(); i += 2)
	{
		if (i + 1 >= temp.size())
			break ;
		if(temp[i].empty() || temp[i +1].empty())
			break;
		if (temp[i].back() > temp[i+1].back() && (int)temp[i+1].size() == chunkSize)
			std::swap(temp[i], temp[i +1]);	
	}
	vec.clear();
	//put the chunks back to vec for the next iteration
	for (size_t i = 0; i < temp.size(); i++)
	{
		for (auto it : temp[i])
			vec.emplace_back(it);
	}
	//recursively call itself again to do larger chunks
	temp.clear();
	sortVector(vec, chunkSize * 2);

	chunkVec(vec, temp, chunkSize);

	if (!temp.empty() && (int)temp.back().size() != chunkSize)
	{
		leftover.insert(leftover.end(), temp.back().begin(), temp.back().end());
		temp.pop_back();
	}
	vec.clear();

	//sort elements into main and pend
	std::vector<int> pend;
	for (size_t i = 0; i < temp.size(); i+= 2)
	{
		if (i + 1 >= temp.size())
		{
			pend.insert(pend.end(), temp[i].begin(), temp[i].end());
			break ;
		}
		if(temp[i].empty() || temp[i +1].empty())
			break;
		if (temp[i].back() < temp[i +1].back())
		{
			vec.insert(vec.end(), temp[i].begin(), temp[i].end());
			pend.insert(pend.end(), temp[i+1].begin(), temp[i+1].end());
		}
		else
		{
			pend.insert(pend.end(), temp[i].begin(), temp[i].end());
			vec.insert(vec.end(), temp[i+1].begin(), temp[i+1].end());
		}
	}
	
	int prev = -1;
	int next = -1;
	int jNumb = 2;
	int left = pend.size();
	
	while (left > 0)
	{
		prev = next;
		next = jacobsthal(jNumb);
		jNumb++;
		if (next > (int)pend.size())
			break ;
		for(int i = next; i > prev; i--)
		{
			auto it = std::lower_bound(vec.begin(), vec.end(), pend[i]);
			vec.insert(it, pend[i]);
			left--;
		}
		
	}
	if (left > 0)
	{
		for(int i = (int)pend.size() -1; i > prev; i--)
		{
			auto it = std::lower_bound(vec.begin(), vec.end(), pend[i]);
			vec.insert(it, pend[i]);
		}
	}
	//put leftover back into main
	vec.insert(vec.end(), leftover.begin(), leftover.end());
	
	leftover.clear();
	temp.clear();
	pend.clear();
}
	
	void PmergeMe::executeVector(char *argv[])
	{
		//start timer
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i = 1; argv[i]; i++)
			vector.push_back(std::stoi(argv[i]));
		sortVector(vector, 1);
		
		//end timer	
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration<double, std::micro>(stop - start);
		// printVector();
		std::cout << "Time to process a range of " << std::setw(4) << before.size() << " elements with std::vector : " << duration.count() << " us" << std::endl;
	}

void PmergeMe::chunkLst(std::list<int>& lst, std::list<std::list<int>>& temp, int chunkSize)
{
	int pair = 0;
	int nbr = 1;
	auto chunkIt = temp.end();

	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if (chunkIt == temp.end())
		{	
			temp.emplace_back();
			chunkIt--;
		}
		chunkIt->emplace_back(*it);
		if (nbr % chunkSize == 0)
		{
			pair++;
			chunkIt++;
		}
		nbr++;
	}
	if (temp.size() > 1 && temp.back().empty())
		temp.pop_back();

	// std::cout << "CHUNKS = \n";
	// for(auto it : temp)
	// {
	// 	for (auto it2 : it)
	// 		std::cout << it2 <<' ';
	// 	std::cout << std::endl;
	// }
	
}

void PmergeMe::sortList(std::list<int>& lst, int chunkSize)
{
	if (chunkSize > (int)lst.size() / 2)
		return ;
	std::list<std::list<int>> temp;
	// //create the chunks as sub vectors of temp
	chunkLst(lst, temp, chunkSize);
	//sort the chunks with its neighbour
	for(auto it = temp.begin(); it != temp.end(); it++)
	{
		auto it2 = it;
		it2++;
		if (it2 == temp.end())
			break;
		if (it->empty() || it2->empty())
			break;
		if(it->back() > it2->back() && (int)it2->size() == chunkSize)
			std::swap(*it, *it2);
		it++;
	}
	
	lst.clear();
	// //put the chunks back to vec for the next iteration
	for(auto it : temp)
	{
		for (auto it2 : it)
			lst.emplace_back(it2);
	}
	
	// //recursively call itself again to do larger chunks
	temp.clear();
	sortList(lst, chunkSize * 2);

	chunkLst(lst, temp, chunkSize);
	std::list<int> surplus;
	//save last element in leftover, if it is not complete
	if (!temp.empty() && (int)temp.back().size() != chunkSize)
	{
		auto it = surplus.begin();
		surplus.splice(it, temp.back());
	}
	
	
	// if (!temp.empty() && (int)temp.back().size() != chunkSize)
	// {
		// 	leftover.insert(leftover.end(), temp.back().begin(), temp.back().end());
		// 	temp.pop_back();
		// }
		// lst.clear();
		
		
	lst.clear();
	
//sort elements into main(lst) and pend
	std::list<int> pend;
	for(auto it = temp.begin(); it != temp.end(); it++)
	{
		auto it2 = it;
		it2++;
		// auto pendIt = pend.end();
		if (it2 == temp.end())
		{
			pend.splice(pend.end(), *it);
			break;
		}
		if (it->empty() || it2->empty())
			break;
		if (it->back() < it2->back())
		{
			lst.splice(lst.end(), *it);
			pend.splice(pend.end(), *it2);
		}
		else
		{
			lst.splice(lst.end(), *it2);
			pend.splice(pend.end(), *it);		
		}
		it++;
	}
	//sort elements into main(lst) and pend
	// std::vector<int> pend;
	// for (size_t i = 0; i < temp.size(); i+= 2)
	// {
	// 	if (i + 1 >= temp.size())
	// 	{
	// 		pend.insert(pend.end(), temp[i].begin(), temp[i].end());
	// 		break ;
	// 	}
	// 	if(temp[i].empty() || temp[i +1].empty())
	// 		break;
	// 	if (temp[i].back() < temp[i +1].back())
	// 	{
	// 		lst.insert(lst.end(), temp[i].begin(), temp[i].end());
	// 		pend.insert(pend.end(), temp[i+1].begin(), temp[i+1].end());
	// 	}
	// 	else
	// 	{
	// 		pend.insert(pend.end(), temp[i].begin(), temp[i].end());
	// 		lst.insert(lst.end(), temp[i+1].begin(), temp[i+1].end());
	// 	}
	// }

	std::cout << "LIST = ";
	for(auto it : lst)
		std::cout << it <<' ';
	std::cout << std::endl;
	
	std::cout << "PEND = ";
	for(auto it : pend)
		std::cout << it <<' ';
	std::cout << std::endl;

	std::cout << "SURPLUS = ";
	for(auto it : surplus)
		std::cout << it <<' ';
	std::cout << std::endl;
	
	int prev = 0;
	int next = 0;
	int jNumb = 2;
	int left = pend.size();
	auto pendIt = pend.begin();
	
	while (left > 0)
	{
		prev = next;
		next = jacobsthal(jNumb);
		jNumb++;
		if (next > (int)pend.size())
			break ;
		std::advance(pendIt, next - prev);

		for (auto rit = std::make_reverse_iterator(pendIt); rit != pend.rend(); ++rit)
		{
			auto it = std::lower_bound(lst.begin(), lst.end(), *rit);
			lst.insert(it, *rit);
			left--;
			prev++;
			if (prev == next)
				break;
		}

		
		// for(int i = next ; i > prev; i--)
		// {
		// 	auto it = std::lower_bound(lst.begin(), lst.end(), *pendIt);
		// 	lst.insert(it, *pendIt);
		// 	pendIt--;
		// 	left--;
		// }
	}

	if (left > 0)
	{
		auto pendIt = pend.rbegin();
		// std::advance(pendIt, (int)pend.size() -2); //maybe -2
		for(int i = (int)pend.size(); i > prev; i--)
		{
			auto it = std::lower_bound(lst.begin(), lst.end(), *pendIt);
			lst.insert(it, *pendIt);
			pendIt++;
		}
	}
	// //put surplus back into main
	lst.splice(lst.end(), surplus);
	
	std::cout << "LIST = ";
	for(auto it : lst)
		std::cout << it <<' ';
	std::cout << std::endl;
	// lst.insert(lst.end(), leftover.begin(), leftover.end());
	
	surplus.clear();
	temp.clear();
	pend.clear();
}
	
	void PmergeMe::executeList(char *argv[])
	{
		//start timer
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i = 1; argv[i]; i++)
			list.push_back(std::stoi(argv[i]));
		sortList(list, 1);
		
		//end timer	
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration<double, std::micro>(stop - start);
		std::cout << "Time to process a range of " << std::setw(4) << before.size() << " elements with std::list   : " << duration.count() << " us" << std::endl;
	}

	

	void PmergeMe::printVector()
	{
		std::cout << "After:  ";	
		for(auto it : vector)
			std::cout << it <<' ';
		std::cout << std::endl;
	}
	
	void PmergeMe::printBefore()
	{
		std::cout << "Before: ";
		for(auto it : before)
			std::cout << it <<' ';
		std::cout << std::endl;
	}
	
	void PmergeMe::printList()
	{
		std::cout << "LIST = ";
		for(auto it : list)
			std::cout << it <<' ';
		std::cout << std::endl;
	}