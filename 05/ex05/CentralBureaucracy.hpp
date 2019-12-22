/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:27:17 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 19:54:55 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include "OfficeBlock.hpp"

class CentralBureaucracy
{
private:
	OfficeBlock offices[20];
	Intern interns[20];
	int bureaucratCount;
	int inQueue;
	std::string *queue;
public:
	CentralBureaucracy();
	virtual ~CentralBureaucracy();

	class BureaucratyFullException: public std::exception {
		virtual const char* what() const throw() {
			return "CentralBureaucracyException: Every post has already been assigned";
		}
	};

	void feed(Bureaucrat const &bureaucrat);
	void queueUp(std::string const &target);
	void doBureaucracy(void);
};

CentralBureaucracy &operator<<(CentralBureaucracy &bureau, Bureaucrat const &bureaucrat);
CentralBureaucracy &operator<<(CentralBureaucracy &bureau, std::string const &target);

#endif
