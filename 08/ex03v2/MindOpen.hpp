/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:54:37 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/30 14:45:25 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include <sstream>
# include <iostream>
# include <fstream>
# include <string>
# include <array>
# include <deque>
# include "Program.hpp"

class MindOpen
{
private:
	std::string moriginal;
	Program program;
public:
	MindOpen();
	MindOpen(MindOpen const &other);
	virtual ~MindOpen();

	MindOpen &operator=(MindOpen const &other);

	bool loadFromString(std::string const &str);
	bool loadFromFile(std::string const &filename);

	void execute(void);
};

#endif
