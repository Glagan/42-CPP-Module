/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:24:39 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 19:52:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
private:
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();

	class iterator
	{
	private:
		int pointer;
	public:
		iterator();
		iterator(iterator const &other);
		~iterator();

		iterator &operator=(iterator const &other);

		T operator*();

		bool operator==(iterator const &other) const;
		bool operator!=(iterator const &other) const;
		bool operator<(iterator const &other) const;
		bool operator<=(iterator const &other) const;
		bool operator>(iterator const &other) const;
		bool operator>=(iterator const &other) const;

		iterator operator++(int);
		iterator operator++();
		iterator operator--(int);
		iterator operator--();
	};

	MutantStack<T> &operator=(MutantStack<T> const &other);

	iterator begin(void) const;
	iterator rbegin(void) const;
	iterator cbegin(void) const;
	iterator crbegin(void) const;
	iterator end(void) const;
	iterator rend(void) const;
	iterator cend(void) const;
	iterator crend(void) const;

	bool empty(void) const;
	unsigned int size(void) const;
	T top(void) const;
	void push(T value);
	T pop(void);
};

#endif
