/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:23:35 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/15 19:39:55 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void)
{
	Logger logger("log");

	logger.log("logToConsole", "Initialization...");
	logger.log("logToConsole", "Starting engines...");
	logger.log("logToConsole", "Next messages will be sent to file");
	logger.log("logToFile", "Logging messages of Logger");
	logger.log("logToFile", "I'm on another line");
	logger.log("logToFile", "This is the last message");
	logger.log("logToConsole", "It's over.");
	return (0);
}
