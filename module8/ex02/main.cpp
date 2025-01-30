/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:20:43 by clundber          #+#    #+#             */
/*   Updated: 2025/01/23 09:58:28 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include<vector>
int main()
{
	try
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		// std::cout << mstack.top() << std::endl;
		mstack.pop();
		// std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int> mstack2(mstack);
		// std::cout << mstack.top() << std::endl;
		// std::cout << mstack2.top() << std::endl;
		mstack.push(5);
		mstack2 = mstack;
		mstack.push(6);
		// std::cout << mstack.top() << std::endl;
		// std::cout << mstack2.top() << std::endl;	

		MutantStack<int, std::vector<int>> mstack3;
		mstack3.push(123);
		mstack3.push(234);
		for (auto it : mstack3)
			std::cout << it << std::endl;
		
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}