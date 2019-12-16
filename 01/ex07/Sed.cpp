/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:17:08 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/16 14:13:13 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

std::string Sed::strReplace(std::string line, std::string search, std::string replace)
{
	std::stringstream ss;
	size_t		j;
	size_t		slength(search.length());

	for (size_t i = 0; i < line.length(); i++)
	{
		j = 0;
		while (line[i + j] == search[j] && j < slength)
			j++;
		if (j == slength)
		{
			ss << replace;
			i += (j - 1);
		}
		else
			ss << line[i];
	}
	return (ss.str());
}

void Sed::replace(std::string filename, std::string search, std::string replace)
{
	std::ifstream	file(filename);
	std::ofstream	output(filename + ".replace", std::ios::trunc);
	std::string		line;

	if (!file.is_open())
		throw "error: Input File couldn't be opened.";
	else if (!file.is_open())
		throw "error: Output File couldn't be opened.";
	else if (search.length() == 0)
		throw "error: Search string is empty.";
	else if (replace.length() == 0)
		throw "error: Replace string is empty.";
	while (std::getline(file, line))
	{
		output << Sed::strReplace(line, search, replace);
		if (!file.eof())
			output << '\n';
    }
	file.close();
	output.close();
}

