/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:54:20 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/29 19:39:46 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MindOpen.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "MindOpen: error: missing program name" << std::endl;
	}
	else
	{
		MindOpen mo;
		if (!mo.loadFromFile(argv[1]))
			std::cerr << "MindOpen: error: could not load program " << argv[1] << std::endl;
		else
			mo.execute();
	}
	return (0);
}
