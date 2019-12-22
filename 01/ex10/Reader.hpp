/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:47:40 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:58:51 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_HPP
# define READER_HPP

# include <iostream>
# include <fstream>
# include <string>

class Reader
{
private:
public:
	Reader();
	virtual ~Reader();

	static void readFile(std::istream &stream);
	static void openReadFile(std::string const &filename);
};

#endif