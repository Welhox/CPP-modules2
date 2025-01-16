/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:07 by clundber          #+#    #+#             */
/*   Updated: 2025/01/16 14:55:17 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): maxSize(1) {}
Span::Span(uint size): maxSize(size) {}
Span::Span(Span& other): maxSize(other.maxSize), container(other.container) {}
Span::~Span() {}
Span& Span::operator=(Span& other) 
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->container = other.container;
	}
	return(*this);
}

void	Span::addNumber(int newNumber)
{
	if (container.size() < maxSize)
		{
			container.insert(newNumber);
		}
	else
		throw std::invalid_argument("Span already at max capacity");
}

size_t	Span::shortestSpan()
{
	size_t	spanMin = __SIZE_MAX__;
	size_t current;
	int		previous;
	if (!container.empty())
	{
		previous = *container.begin();
		for (auto it : container)
		{
			if (it == previous)
				continue;
			current = it - previous;
			spanMin = std::min(spanMin, current);
			previous = it;
		}
	}
	if (spanMin == __SIZE_MAX__)
		throw std::invalid_argument("No span found");
	return (spanMin);
}

size_t	Span::longestSpan()
{
	size_t span = 0;

	if (!container.empty())
		span = (*container.rbegin() - *container.begin());
	if (span == 0)
		throw std::invalid_argument("No span found");
	std::cout << "END == " << *container.rbegin() << "BEGIN = " << *container.begin() << std::endl;
	return (span);
}