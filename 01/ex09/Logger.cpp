/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:24:27 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 18:23:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string const &logfile)
{
	this->olog.open(logfile, std::ios::app);
}

Logger::~Logger()
{
	if (this->olog.is_open())
		this->olog.close();
}

std::string Logger::makeLogEntry(std::string const &value)
{
	std::stringstream ss;
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	ss << std::setfill('0') << "[" << (utc_tm.tm_year + 1900) << "/"
			<< std::setw(2) << utc_tm.tm_mon << "/"
			<< std::setw(2) << utc_tm.tm_mday << ":"
			<< std::setw(2) << utc_tm.tm_hour << "h"
			<< std::setw(2) << utc_tm.tm_min << "m"
			<< std::setw(2) << utc_tm.tm_sec << "s] ";
	ss << value;
	return (ss.str());
}

void Logger::logToConsole(std::string const &value)
{
	std::cout << this->makeLogEntry(value) << std::endl;
}

void Logger::logToFile(std::string const &value)
{
	if (!this->olog.is_open())
		throw "error: Cannot write to log file.";
	olog << this->makeLogEntry(value) << std::endl;
}

void Logger::log(std::string const &dest, std::string const &message)
{
	int index[255];
	void (Logger::* const actions[2])(std::string const &value) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};

	index[(int)'C'] = 0;
	index[(int)'F'] = 1;
	if (dest == "logToConsole"
		|| dest == "logToFile")
		(this->*actions[index[(int)dest[5]]])(message);
	else
		throw "error: Invalid log destination.";
}
