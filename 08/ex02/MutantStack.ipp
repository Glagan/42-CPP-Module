/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.ipp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:21:31 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 16:04:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack():
	std::deque<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other):
	std::deque<T>(other)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
	this->c = other.c;
	return (*this);
}

template<typename T>
void MutantStack<T>::push(T const &value)
{
	this->push_back(value);
}

template<typename T>
void MutantStack<T>::pop(void)
{
	this->pop_back();
}

template<typename T>
T &MutantStack<T>::top(void)
{
	return (this->back());
}

template<typename T>
const T &MutantStack<T>::top(void) const
{
	return (this->back());
}
