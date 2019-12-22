/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:24:06 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:58:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <sstream>
# include <chrono>

class Logger
{
private:
	std::ofstream olog;

	std::string makeLogEntry(std::string const &value);
	void logToConsole(std::string const &value);
	void logToFile(std::string const &value);
public:
	Logger(std::string const &logfile);
	virtual ~Logger();

	void log(std::string const &dest, std::string const &message);
};

#endif