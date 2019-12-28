/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:04:02 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 15:29:47 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cctype>

template<typename T>
void iter(T arr[], size_t length, void (*f)(T elt));

# include "iter.ipp"

#endif
