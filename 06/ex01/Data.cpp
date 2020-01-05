/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:36:08 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/05 16:14:42 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void *serialize(void)
{
	static std::string alphabet = "0123456789" \
		"abcdefghijklmopqrstuvxyz" \
		"ABCDEFGHIJKLMOPQRSTUVXYZ";
	static size_t alphabetLength = alphabet.length();
	char *raw;
	int n;
	int i;

	n = rand() % 424242;
	raw = new char[20];
	for (i = 0; i < 8; i++)
		raw[i] = alphabet[rand() % alphabetLength];
	raw[i++] = static_cast<unsigned char>(n >> 24);
	raw[i++] = static_cast<unsigned char>(n >> 16);
	raw[i++] = static_cast<unsigned char>(n >> 8);
	raw[i++] = static_cast<unsigned char>(n);
	for (i = 0; i < 8; i++)
		raw[i + 12] = alphabet[rand() % alphabetLength];
	return (raw);
}

Data *deserialize(void *raw)
{
	Data *d = new Data;

	d->s1 = std::string(static_cast<char*>(raw), 8);
	d->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 12);
	d->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return (d);
}
