/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:16:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 20:27:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <sstream>

class Sed
{
private:
	static std::string strReplace(std::string const &line, std::string const &search, std::string const &replace);
public:
	Sed();
	~Sed();

	static void replace(std::string const &filename, std::string const &search, std::string const &replace);
};

#endif