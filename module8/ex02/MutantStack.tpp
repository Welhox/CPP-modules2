/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:20 by clundber          #+#    #+#             */
/*   Updated: 2025/01/21 17:09:33 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T,typename Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>(){}

template <typename T,typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other): std::stack<T, Container>(other){}

//parameterized constructor missing
template <typename T,typename Container>
MutantStack<T, Container>::~MutantStack(){}

template <typename T,typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);   
    return (*this);
}

template <typename T,typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(){return c.begin();}

template <typename T,typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(){return c.end();}

template <typename T,typename Container>
typename MutantStack<T, Container>::constIterator MutantStack<T, Container>::begin() const {return c.begin();}

template <typename T,typename Container>
typename MutantStack<T, Container>::constIterator MutantStack<T, Container>::end() const {return c.end();}
