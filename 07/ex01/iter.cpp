/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:04:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 15:06:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void iter(T arr[], size_t length, void (*f)(T elt))
{
	for (size_t i = 0; i < length; i++)
		(*f)(arr[i]);
}
