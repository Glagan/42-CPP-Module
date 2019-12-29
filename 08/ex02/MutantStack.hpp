/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:24:39 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 15:59:06 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template<typename T>
class MutantStack: public std::deque<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();

	MutantStack<T> &operator=(MutantStack<T> const &other);

	void push(T const &value);
	void pop(void);
	T &top(void);
	const T &top(void) const;
};

# include "MutantStack.ipp"

#endif
