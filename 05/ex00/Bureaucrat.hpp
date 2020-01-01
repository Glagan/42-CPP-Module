/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:28:54 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/01 19:43:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	Bureaucrat();

	std::string const name;
	int grade;
public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const &getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
