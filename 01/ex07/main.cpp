/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:06:44 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 18:51:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
		std::cout << "error: Invalid number of arguments.\nUsage: filename search replace" << std::endl;
	else
		Sed::replace(argv[1], argv[2], argv[3]);
	return (0);
}
