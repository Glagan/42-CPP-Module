/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:54:57 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 14:59:42 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

template<typename T>
void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T &a, T &b)
{
	if (b > a)
		return (a);
	return (b);
}

template<typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}
