/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:31:53 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 15:55:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array():
	length(0), elts(nullptr)
{
}

template<typename T>
Array<T>::Array(unsigned int n):
	length(n), elts(nullptr)
{
	this->elts = new T[n]();
}

template<typename T>
Array<T>::Array(Array const &other)
{
	if (this->length > 0)
		delete[] this->elts;
	this->elts = nullptr;
	if (other.length > 0)
	{
		this->elts = new T[other.length];
		for (unsigned int i = 0; i < other.length; i++)
			this->elts[i] = other.elts[i];
	}
	this->length = other.length;
}

template<typename T>
Array<T>::~Array()
{
	if (this->length > 0)
		delete[] this->elts;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (this->length > 0)
		delete[] this->elts;
	this->elts = nullptr;
	if (other.length > 0)
	{
		this->elts = new T[other.length];
		for (unsigned int i = 0; i < other.length; i++)
			this->elts[i] = other.elts[i];
	}
	this->length = other.length;
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->length)
		throw Array::InvalidIndexException();
	return (this->elts[index]);
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return (this->length);
}
