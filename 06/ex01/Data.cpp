/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:36:08 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/27 18:58:36 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void *serialize(void)
{
	static std::string alphabet = "abcdefghijklmopqrstuvxyz" \
								"ABCDEFGHIJKLMOPQRSTUVXYZ";
	static size_t alphabetLength = alphabet.length();
	char *raw;
	int n;
	int i = 0;

	n = rand() % 424242;
	raw = new char[20];
	for ( ; i < 8; i++)
		raw[i] = alphabet[rand() % alphabetLength];
	raw[i++] = static_cast<unsigned char>(n >> 24);
	raw[i++] = static_cast<unsigned char>(n >> 16);
	raw[i++] = static_cast<unsigned char>(n >> 8);
	raw[i++] = static_cast<unsigned char>(n);
	for ( ; i < 8; i++)
		raw[i + 12] = alphabet[rand() % alphabetLength];
	return (raw);
}

Data *deserialize(void *raw)
{
	Data *d = new Data;

	d->s1.resize(8);
	for (int i = 0; i < 8; i++)
		d->s1[i] = static_cast<char*>(raw)[i];
	d->n = 0;
	d->n = (static_cast<unsigned char*>(raw)[8] << 24)
			| (static_cast<unsigned char*>(raw)[9] << 16)
			| (static_cast<unsigned char*>(raw)[10] << 8)
			| (static_cast<unsigned char*>(raw)[11]);
	d->s2.resize(8);
	for (int i = 0; i < 8; i++)
		d->s2[i] = static_cast<char*>(raw)[i + 12];
	return (d);
}
