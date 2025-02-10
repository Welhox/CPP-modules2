/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:58 by clundber          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:39 by clundber         ###   ########.fr       */
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
		for (int i = 1; argv[i]; i++)
		{
			int temp = std::stoi(argv[i]);
			if (temp < 0)
				throw std::invalid_argument("Error");
			if (i > 3100)
				throw std::invalid_argument("Error");
		}
		for (int i = 1; argv[i]; i++)
			before.push_back(std::stoi(argv[i]));
		if (duplicateCheck())
			throw std::invalid_argument("Error");
	}

	void PmergeMe::sortVector(std::vector<int>& vec)
	{
		if (vec.size() < 2)
			return;
		auto mid = vec.begin() + vec.size() / 2;
		std::vector<int> left(vec.begin(), mid);
		std::vector<int> right(mid, vec.end());
		sortVector(left);
		sortVector(right);
		std::vector<int> temp;
		auto itL = left.begin();
		auto itR = right.begin();
		while (itL != left.end() && itR != right.end())
		{
			if (*itL == *itR)
				throw std::invalid_argument("Error");
			else if (*itL < *itR)
				temp.push_back(*itL++);
			else
				temp.push_back(*itR++);
		}
		while (itL != left.end())
        {
			temp.push_back(*itL++);
		}
    	while (itR != right.end())
		{
        	temp.push_back(*itR++);
		}
		vec = temp;
		return ;
	}

	void PmergeMe::sortList(std::list<int>& lst)
	{
		if (lst.size() < 2)
			return;
		auto mid = std::next(lst.begin(), lst.size() / 2);
		std::list<int> left;
		std::list<int> right;
		left.splice(left.begin(), lst, lst.begin(), mid);
		right.splice(right.begin(), lst, lst.begin(), lst.end());		
		sortList(left);
		sortList(right);
		std::list<int> temp;
		auto itL = left.begin();
		auto itR = right.begin();
		while (itL != left.end() && itR != right.end())
		{
			if (*itL == *itR)
				throw std::invalid_argument("Error");
			else if (*itL < *itR)
				temp.push_back(*itL++);
			else
				temp.push_back(*itR++);
		}
		while (itL != left.end())
        {
			temp.push_back(*itL++);
		}
    	while (itR != right.end())
		{
        	temp.push_back(*itR++);
		}
		lst = temp;
		return ;
	}

	
	void PmergeMe::executeVector(char *argv[])
	{
		//start timer
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i = 1; argv[i]; i++)
			vector.push_back(std::stoi(argv[i]));
		sortVector(vector);
		
		//end timer	
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration<double, std::micro>(stop - start);
		printVector();
		std::cout << "Time to process a range of " << std::setw(4) << before.size() << " elements with std::vector : " << duration.count() << " us" << std::endl;
	}

	
	void PmergeMe::executeList(char *argv[])
	{
		//start timer
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i = 1; argv[i]; i++)
			list.push_back(std::stoi(argv[i]));
		sortList(list);
		
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