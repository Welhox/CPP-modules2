/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:31:33 by casimirri         #+#    #+#             */
/*   Updated: 2025/02/07 14:40:50 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(): arg(""){};
RPN::~RPN(){};
RPN::RPN(RPN& other)
{
	*this = other;
}
RPN& RPN::operator=(RPN& other)
{
	if (this != &other)
	{
		this->container = other.container;
		this->arg = other.arg;
	}
	return (*this);
}

RPN::RPN(std::string newArg): arg(newArg)
{
	if (arg.empty())
		throw std::invalid_argument("Error");
	std::regex pattern(R"(^(((-?\d+) )+([+\-/*] )*)*[+\-/*]?$)");
	if (!std::regex_match(arg, pattern))
		throw std::invalid_argument("Error");
	
}
void	RPN::doOperator(std::string& op)
{
	long long bottom;
	long long top;
	long long result = 0;

	if (container.size() < 2)
		throw std::invalid_argument("Error");

	top = container.top();
	container.pop();
	bottom = container.top();
	container.pop();
	switch (op[0])
	{
	case '+':
		result = bottom + top;
		break;
	case '-':
		result = bottom - top;
		break;
	case '/':
		result = bottom / top;
		break;
	case '*':
		result = bottom * top;
		break;
	default:
		break;
	}
	if (result > INT_MAX || result < INT_MIN)
		throw std::invalid_argument("Too large result");
	container.push((int)result);
	
}

int RPN::calculate()
{
	if (arg.empty())
		return 0;
	std::string operators = "-+/*";
	std::stringstream argStream(arg);
	std::string block;
	std::regex numReg(R"(^-?\d+$)");
	while (argStream >> block)
	{
		if (block[0] == ' ')
		 	continue;
		else if (std::regex_match(block, numReg))
		{
			int temp = std::stoi(block);
			container.push(temp);
		}
		else if (operators.find(block) != std::string::npos)
		{
			doOperator(block);
		}
		else
			throw std::invalid_argument("Error");
	}

	return 0;
}

void RPN::printStack()
{
	std::stack<int> temp = container;
	std::cout << "Stack in reverse: \n";
	while (!container.empty())
	{
		std::cout << container.top() << std::endl;
		container.pop();
	}
}
