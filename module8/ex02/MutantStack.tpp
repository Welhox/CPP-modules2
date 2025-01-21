/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:20 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 11:58:59 by casimirri        ###   ########.fr       */
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
    {
        std::stack<T>::operator=(other);   
    }
    return (*this);
}

