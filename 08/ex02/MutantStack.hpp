/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:24:39 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/09 15:21:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();

	class iterator: public std::deque<T>::iterator
	{
	public:
		iterator();
		iterator(iterator const &other);
		iterator(typename std::deque<T>::iterator const &other);
		virtual ~iterator();
	};
	class const_iterator: public std::deque<T>::const_iterator
	{
	public:
		const_iterator();
		const_iterator(iterator const &other);
		const_iterator(const_iterator const &other);
		const_iterator(typename std::deque<T>::const_iterator const &other);
		virtual ~const_iterator();
	};
	class reverse_iterator: public std::deque<T>::reverse_iterator
	{
	public:
		reverse_iterator();
		reverse_iterator(reverse_iterator const &other);
		reverse_iterator(typename std::deque<T>::reverse_iterator const &other);
		virtual ~reverse_iterator();
	};
	class const_reverse_iterator: public std::deque<T>::const_reverse_iterator
	{
	public:
		const_reverse_iterator();
		const_reverse_iterator(reverse_iterator const &other);
		const_reverse_iterator(const_reverse_iterator const &other);
		const_reverse_iterator(typename std::deque<T>::const_reverse_iterator const &other);
		virtual ~const_reverse_iterator();
	};

	MutantStack<T> &operator=(MutantStack<T> const &other);

	typename MutantStack<T>::iterator begin(void);
	typename MutantStack<T>::const_iterator begin(void) const;
	typename MutantStack<T>::reverse_iterator rbegin(void);
	typename MutantStack<T>::const_reverse_iterator rbegin(void) const;
	typename MutantStack<T>::iterator end(void);
	typename MutantStack<T>::const_iterator end(void) const;
	typename MutantStack<T>::reverse_iterator rend(void);
	typename MutantStack<T>::const_reverse_iterator rend(void) const;
};

# include "MutantStack.ipp"

#endif
