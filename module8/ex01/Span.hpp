/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:17 by clundber          #+#    #+#             */
/*   Updated: 2025/01/20 12:15:36 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class Span
{
private:
	unsigned int maxSize; 
	std::set <int>container;
	
public:	
	//constructors and destructors
	Span();
	Span(uint size);
	Span(const Span&);
	Span(Span&);
	~Span();

	//operator overloads
	Span& operator=(Span&);
	Span& operator=(const Span&);
	
	//methods
	void	addNumber(int newNumber);
	void	addRange(int start, int end);
	size_t	shortestSpan();
	size_t	longestSpan();
	void	printRange();
};