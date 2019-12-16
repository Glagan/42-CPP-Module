/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:47:40 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/16 14:37:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
# define READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>

class Reader
{
private:
public:
	Reader();
	~Reader();

	static void readFile(std::istream &stream);
	static void openReadFile(std::string const &filename);
};

#endif