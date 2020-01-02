/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:05:09 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/02 17:18:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	Form *(*generators[4])(std::string const &);
public:
	Intern();
	Intern(Intern const &other);
	virtual ~Intern();

	class FormDoesNotExistException: public std::exception {
		virtual const char* what() const throw();
	};

	Intern &operator=(Intern const &other);

	Form *makeForm(std::string const &formName, std::string const &target) const;
};

#endif
