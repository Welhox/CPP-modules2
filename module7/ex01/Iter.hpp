/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:32:51 by casimirri         #+#    #+#             */
/*   Updated: 2024/11/05 23:55:55 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename Len, typename Func>
void    iter(T **array, Len len, Func func)
{
    try
    {
        for(Len i = 0; i < len; i++)
        {
            func(array[i]);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}