/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:31:54 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/04 15:38:17 by ncolomer         ###   ########.fr       */
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
	size_t length;
	T *elts;
public:
	Array();
	Array(size_t n);
	Array(Array<T> const &other);
	virtual ~Array();

	class InvalidIndexException: public std::exception {
		virtual const char* what() const throw();
	};

	Array &operator=(Array const &other);
	T &operator[](size_t index);

	size_t size(void) const;
};

# include "Array.ipp"

#endif
