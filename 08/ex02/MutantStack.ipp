/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.ipp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:21:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/09 15:19:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack():
	std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other):
	std::stack<T>(other)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T>::iterator::iterator():
	std::deque<T>::iterator()
{
}

template<typename T>
MutantStack<T>::iterator::iterator(typename MutantStack<T>::iterator const &other):
	std::deque<T>::iterator(other)
{
}

template<typename T>
MutantStack<T>::iterator::iterator(typename std::deque<T>::iterator const &other):
	std::deque<T>::iterator(other)
{
}

template<typename T>
MutantStack<T>::iterator::~iterator()
{
}

template<typename T>
MutantStack<T>::const_iterator::const_iterator():
	std::deque<T>::const_iterator()
{
}

template<typename T>
MutantStack<T>::const_iterator::const_iterator(typename MutantStack<T>::iterator const &other):
	std::deque<T>::const_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_iterator::const_iterator(typename MutantStack<T>::const_iterator const &other):
	std::deque<T>::const_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_iterator::const_iterator(typename std::deque<T>::const_iterator const &other):
	std::deque<T>::const_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_iterator::~const_iterator()
{
}

template<typename T>
MutantStack<T>::reverse_iterator::reverse_iterator():
	std::deque<T>::reverse_iterator()
{
}

template<typename T>
MutantStack<T>::reverse_iterator::reverse_iterator(typename MutantStack<T>::reverse_iterator const &other):
	std::deque<T>::reverse_iterator(other)
{
}

template<typename T>
MutantStack<T>::reverse_iterator::reverse_iterator(typename std::deque<T>::reverse_iterator const &other):
	std::deque<T>::reverse_iterator(other)
{
}

template<typename T>
MutantStack<T>::reverse_iterator::~reverse_iterator()
{
}

template<typename T>
MutantStack<T>::const_reverse_iterator::const_reverse_iterator():
	std::deque<T>::const_reverse_iterator()
{
}

template<typename T>
MutantStack<T>::const_reverse_iterator::const_reverse_iterator(typename MutantStack<T>::reverse_iterator const &other):
	std::deque<T>::const_reverse_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_reverse_iterator::const_reverse_iterator(typename MutantStack<T>::const_reverse_iterator const &other):
	std::deque<T>::const_reverse_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_reverse_iterator::const_reverse_iterator(typename std::deque<T>::const_reverse_iterator const &other):
	std::deque<T>::const_reverse_iterator(other)
{
}

template<typename T>
MutantStack<T>::const_reverse_iterator::~const_reverse_iterator()
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
	this->c = other.c;
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}
