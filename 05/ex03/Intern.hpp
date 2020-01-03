/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:05:09 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 14:13:29 by ncolomer         ###   ########.fr       */
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
	class Pair {
	private:
		Pair();

		std::string const name;
		Form *(*fct)(std::string const &);
	public:
		Pair(std::string const &name, Form *(*fct)(std::string const &));
		Pair(Pair const &other);
		virtual ~Pair();

		Pair &operator=(Pair const &other);

		bool correspond(std::string const &name) const;
		Form *execute(std::string const &target) const;
	};
	Pair *generators[9];
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
