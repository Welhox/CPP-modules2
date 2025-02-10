/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:20 by clundber          #+#    #+#             */
/*   Updated: 2025/02/10 15:31:46 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <vector>
#include <iostream>

class PmergeMe
{
private:
	std::list<int> list;
	std::vector<int> vector;
	bool	uneven = false;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe&);
	PmergeMe& operator=(PmergeMe&);
	void argVal(char* argv[]);
	void executeVector(char *argv[]);
	void executeList(char *argv[]);
	void printVector();
	void printList();
	void sortVector();
	
	// template <typename container>
	void pairVector(std::vector<std::vector<int>>& pairVec, int pairSize);
};