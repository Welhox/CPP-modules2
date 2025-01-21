/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:20 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 16:01:44 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other){}

//parameterized constructor missing
template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);   
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){return c.begin();}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){return c.end();}

template <typename T>
typename MutantStack<T>::constIterator MutantStack<T>::begin() const {return c.begin();}

template <typename T>
typename MutantStack<T>::constIterator MutantStack<T>::end() const {return c.end();}
