/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:21:58 by clundber          #+#    #+#             */
/*   Updated: 2025/02/10 15:54:26 by clundber         ###   ########.fr       */
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
	void PmergeMe::pairVector(std::vector<std::vector<int>>& pairVec, int pairSize)
	{
		(void)pairSize;
		// (void)pairVec;
		
		if (pairVec.size() <= 1)
			return;

		std::vector<std::vector<int>> temp;
		for (auto it = pairVec.begin(); it != pairVec.end(); it++)
		{
			auto it2 = std::next(it);
			if (it2 != pairVec.end())
			{
				if (it2[0] < it[0])
					std::swap(*it, *it2);
				temp.push_back({(*it)[0], (*it2)[0]});
				it = it2;
			}
			else
				break; //need to store the odd value
		}
		pairVector(temp, 2);
		
	}
	
	void PmergeMe::executeVector(char *argv[])
	{
		//start timer
		for (int i = 1; argv[i]; i++)
			vector.emplace_back(std::stoi(argv[i]));
		std::vector<std::vector<int>> temp;
		for (auto it = vector.begin(); it != vector.end(); it++)
		{
			auto it2 = std::next(it);
			if (it2 != vector.end())
			{
				temp.push_back({*it, *it2});
				it = it2;
			}
			else
				break; //need to store the odd value
		}
		pairVector(temp, 2);
		std::cout << "Pairs:\n";
    	for (const auto& pair : temp) {
        for (int num : pair)
            std::cout << num << " ";
       	std::cout << "\n";
    }



		//end timer	
	}

	
	void PmergeMe::executeList(char *argv[])
	{
		(void)argv;
	}

	void PmergeMe::printVector()
	{
		for(auto it : vector)
			std::cout << it <<' ';
		std::cout << std::endl;
	}
	
	void PmergeMe::printList()
	{
		
	}