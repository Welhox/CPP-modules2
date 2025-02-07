/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:31:47 by casimirri         #+#    #+#             */
/*   Updated: 2025/02/07 11:32:12 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <regex>
#include <sstream>

class RPN
{
private:
	std::stack<int> container;
	std::string arg;
	
public:
    RPN();
	RPN(RPN& other);
	RPN(std::string arg);
	~RPN();
	RPN& 	operator=(RPN& other);
	
	//Methods
	int 	calculate();
	void	doOperator(std::string& op);
	void 	printStack();
};