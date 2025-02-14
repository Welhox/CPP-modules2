/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:58 by clundber          #+#    #+#             */
/*   Updated: 2025/02/14 15:29:26 by clundber         ###   ########.fr       */
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

    long a = 1;  // J_0
    long b = 1;  // J_1

    for (int i = 2; i <= n; ++i) {
        long next = b + 2 * a;  // Recurrence relation: J_n = J_{n-1} + 2 * J_{n-2}
        a = b;  // Move a to b (J_{n-2} becomes J_{n-1})
        b = next;  // Move b to next (J_{n-1} becomes J_n)
    }

    return b;  // The last value computed is J_n
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