/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:58 by clundber          #+#    #+#             */
/*   Updated: 2025/02/10 18:10:23 by clundber         ###   ########.fr       */
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
	}

	void PmergeMe::sortVector()
	{
		if (vector.size() % 2 == 1)
			uneven = true;
		
	}
	// template <typename container>
	void PmergeMe::pairVector(std::vector<int>& pairVec)
	{
		if (pairVec.size() < 2)
			return;
		auto mid = pairVec.begin() + pairVec.size() / 2;
		std::vector<int> left(pairVec.begin(), mid);
		std::vector<int> right(mid, pairVec.end());
		pairVector(left);
		pairVector(right);
		std::vector<int> temp;
		auto itL = left.begin();
		auto itR = right.begin();
		// pairVec.clear();
		while (itL != left.end() && itR != right.end())
		{
			// std::cout << "what\n";
			if (*itL <= *itR)
			{
				temp.push_back(*itL);
				itL++;
				// std::next(itL, 1);
			}		
			else
			{
				temp.push_back(*itR);
				itR++;
				// std::next(itR, 1);
			}		
		}
		while (itL != left.end())
        {
			temp.push_back(*itL++);
		}
    	while (itR != right.end())
		{
        	temp.push_back(*itR++);
		}
		printVector();
		pairVec = temp;
		printVector();
		return ;
	}
	
	void PmergeMe::executeVector(char *argv[])
	{
		//start timer
		for (int i = 1; argv[i]; i++)
			vector.push_back(std::stoi(argv[i]));
		// std::vector<std::vector<int>> temp;
		pairVector(vector);

		//end timer	
	}

	
	void PmergeMe::executeList(char *argv[])
	{
		(void)argv;
	}

	void PmergeMe::printVector()
	{
		// std::cout << "SIZE OF VECTOR = " << vector.size() << std::endl;
		for(auto it : vector)
			std::cout << it <<' ';
		std::cout << std::endl;
	}
	
	void PmergeMe::printList()
	{
		
	}