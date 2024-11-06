/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimirri <clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:17:10 by casimirri         #+#    #+#             */
/*   Updated: 2024/11/05 23:20:36 by casimirri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b)
{
    return ((a == b) ? b : (a < b) ? a : b);
}

template <typename T>
T max(T a, T b)
{
    return ((a == b) ? b : (a > b) ? a : b);
}