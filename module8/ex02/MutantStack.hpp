/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:27:57 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 13:20:07 by casimirri        ###   ########.fr       */
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
    
    class Iterator 
    {
    private:
        T* ptr;
        
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(T* p);
        
    };
    
    
    // T& top();
    // const T& top();
    // bool empty();
    // size_type size() const;
    // void push(const T& value);
    // void push(T&& value);
    // void emplace(Args&&... args);
    // void pop();
    // void swap(MutantStack& other);
    
    // bool operator==(const MutantStack& left, const MutantStack& right);
    // bool operator!=(const MutantStack& left, const MutantStack& right);
    // bool operator<(const MutantStack& left, const MutantStack& right);
    // bool operator<=(const MutantStack& left, const MutantStack& right);
    // bool operator>(const MutantStack& left, const MutantStack& right);
    // bool operator>=(const MutantStack& left, const MutantStack& right);
};

#include "MutantStack.tpp"
