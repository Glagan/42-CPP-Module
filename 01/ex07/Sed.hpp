/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:16:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 18:51:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Sed
{
private:
	static std::string strReplace(std::string line, std::string search, std::string replace);
public:
	Sed();
	~Sed();

	static void replace(std::string filename, std::string search, std::string replace);
};

#endif