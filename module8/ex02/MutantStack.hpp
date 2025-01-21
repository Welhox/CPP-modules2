/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:27:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 16:09:07 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>

template <typename T> 
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
    MutantStack(const MutantStack& other);
    //parameterized constructor
    ~MutantStack();
    
    MutantStack& operator=(const MutantStack& other);
    
    //brings the underlying container of the stack class into scope
    using std::stack<T>::c;
    
    //make aliases for iterators to correspond with the underlying class and 
    //use typename because deque is a dependent type (<T>), this to instruct the
    //compiler that it is a type (not a static member)
    using iterator = typename std::deque<T>::iterator;
    using constIterator = typename std::deque<T>::const_iterator;
    
    //Iterator functions
    iterator begin();
    iterator end();
    constIterator begin() const;
    constIterator end() const;
};

#include "MutantStack.tpp"
