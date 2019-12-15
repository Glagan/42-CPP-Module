/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:24:06 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:35:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

class Logger
{
private:
	std::ofstream olog;
	std::string logfile;

	std::string makeLogEntry(std::string const &value);
	void logToConsole(std::string const &value);
	void logToFile(std::string const &value);
public:
	Logger(std::string logfile);
	~Logger();

	void log(std::string const &dest, std::string const &message);
};

#endif