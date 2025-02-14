/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:22:20 by clundber          #+#    #+#             */
/*   Updated: 2025/02/14 10:29:48 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <unordered_set>
#include <regex>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> before; 
	std::list<int> list;
	std::vector<int> vector;
	std::vector<int> leftover;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe&);
	PmergeMe& operator=(PmergeMe&);
	bool duplicateCheck();
	void argVal(char* argv[]);
	void executeVector(char *argv[]);
	void executeList(char *argv[]);
	void printVector();
	void printList();
	void sortVector(std::vector<int>&, int);
	void sortList(std::list<int>& vec);
	void chunkVec(std::vector<int>& vec, std::vector<std::vector<int>>& temp, int chunkSize);
	void printBefore();

};