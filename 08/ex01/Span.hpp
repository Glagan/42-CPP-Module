/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/08 16:29:15 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <cmath>
# include <algorithm>

class Span
{
private:
	Span();

	size_t max;
	std::multiset<int> numbers;
public:
	Span(size_t amount);
	Span(Span const &other);
	virtual ~Span();

	class FullSpanException: public std::exception {
		virtual const char* what() const throw();
	};
	class NotEnoughNumbersException: public std::exception {
		virtual const char* what() const throw();
	};

	Span &operator=(Span const &other);

	void addNumber(int value);
	template<typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end);

	size_t shortestSpan(void) const;
	size_t longestSpan(void) const;
};

# include "Span.ipp"

#endif
