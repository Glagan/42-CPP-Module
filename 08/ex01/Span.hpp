/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:41:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 17:39:45 by ncolomer         ###   ########.fr       */
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
		virtual const char* what() const throw() {
			return "SpanException: Span is already full";
		}
	};
	class NotEnoughNumbersException: public std::exception {
		virtual const char* what() const throw() {
			return "SpanException: not enough numbers in Span";
		}
	};

	Span &operator=(Span const &other);

	void addNumber(int value);

	int shortestSpan(void) const;
	int longestSpan(void) const;
};

#endif
