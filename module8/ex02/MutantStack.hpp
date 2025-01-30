/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:27:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/30 16:35:19 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>

//Container added in case other than default underlying container specified
template <typename T,typename Container = std::deque<T>> 
class MutantStack: public std::stack<T, Container>
{
public:
	MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    
    MutantStack& operator=(const MutantStack& other);
    
    //brings the underlying container of the stack class into scope
    using std::stack<T, Container>::c;
    
    //make aliases for iterators to correspond with the underlying class and 
    //use typename because underlying container is a dependent type (<T>), this to instruct the
    //compiler that it is a type (not a static member)
    using iterator = typename Container::iterator;
    using constIterator = typename Container::const_iterator;
    
    //Iterator functions
    iterator begin();
    iterator end();
    constIterator begin() const;
    constIterator end() const;
};

#include "MutantStack.tpp"
