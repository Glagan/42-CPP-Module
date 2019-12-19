/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:47:30 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:16:53 by ncolomer         ###   ########.fr       */
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
		std::cerr << "cato9tails: " << filename  << ": " << std::strerror(errno) << std::endl;
	else
	{
		try
		{
			Reader::readFile(infile);
		}
		catch(char const *e)
		{
			std::cerr << "cato9tails: "<< filename << ": " << e << std::endl;
		}
		infile.close();
	}
}
