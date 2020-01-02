/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:31:54 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:50:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cctype>

template<typename T>
class Array
{
private:
	unsigned int length;
	T *elts;
public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const &other);
	virtual ~Array();

	class InvalidIndexException: public std::exception {
		virtual const char* what() const throw();
	};

	Array &operator=(Array const &other);
	T &operator[](unsigned int index);

	unsigned int size(void) const;
};

# include "Array.ipp"

#endif
