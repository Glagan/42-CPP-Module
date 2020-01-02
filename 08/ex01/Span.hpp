/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 14:51:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span
{
private:
	Span();

	unsigned int max;
	std::vector<int> numbers;
public:
	Span(unsigned int amount);
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

	int shortestSpan(void) const;
	int longestSpan(void) const;
};

# include "Span.ipp"

#endif
