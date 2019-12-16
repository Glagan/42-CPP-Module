/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:47:30 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/16 14:39:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader()
{
}

Reader::~Reader()
{
}

void Reader::readFile(std::istream &stream)
{
	std::string line;

	while (std::getline(stream, line))
	{
		std::cout << line;
		if (!stream.eof())
			std::cout << std::endl;
	}
	if (stream.bad())
		throw "Problem while reading file";
}

void Reader::openReadFile(std::string const &filename)
{
	std::fstream infile(filename);

	if (!infile.is_open() || !infile.good())
		std::cout << "cat: " << filename  << ": " << std::strerror(errno) << std::endl;
	else
	{
		try
		{
			Reader::readFile(infile);
		}
		catch(char const *e)
		{
			std::cout << "cat: "<< filename << ": Exception: " << e << std::endl;
		}
		infile.close();
	}
}
