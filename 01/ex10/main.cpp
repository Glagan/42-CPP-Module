/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:43:55 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:54:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

int main(int argc, char const *argv[])
{
	Reader reader;

	if (argc == 1)
		Reader::readFile(std::cin);
	else
	{
		for (int i = 1; i < argc; i++)
			Reader::openReadFile(argv[i]);
	}
	return (0);
}
