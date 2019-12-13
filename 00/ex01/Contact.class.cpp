/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:02:01 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/13 20:47:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

int Contact::valid_phone(void)
{
	if (this->informations[Field::Phone].length())
}

int Contact::valid_birthday(void)
{
	return (this->birthday[BirthdayField::Day] > 0 && this->birthday[BirthdayField::Day] < 32
		&& this->birthday[BirthdayField::Month] > 0 && this->birthday[BirthdayField::Month] < 13
		&& this->birthday[BirthdayField::Year] > 1900 && this->birthday[BirthdayField::Year] < 2020);
}

bool Contact::set_informations(void)
{
	std::cout << "~~~First Name:\n>";
	std::getline(std::cin, this->informations[Field::FirstName]);
	std::cout << "~~~Last Name:\n>";
	std::getline(std::cin, this->informations[Field::LastName]);
	std::cout << "~~~Nickname:\n>";
	std::getline(std::cin, this->informations[Field::Nickname]);
	std::cout << "~~~Login:\n>";
	std::getline(std::cin, this->informations[Field::Login]);
	std::cout << "~~~Address:\n>";
	std::getline(std::cin, this->informations[Field::Address]);
	std::cout << "~~~E-mail:\n>";
	std::getline(std::cin, this->informations[Field::Email]);
	std::cout << "~~~Phone:\n>";
	std::getline(std::cin, this->informations[Field::Phone]);
	if (!this->valid_phone())
	{
		std::cout << "~~~Invalid Phone Number !~~~" << std::endl;
		return (false);
	}
	std::cout << "~~~Birth [DAY]:\n>";
	std::cin >> this->birthday[BirthdayField::Day];
	std::cout << "~~~Birth [MONTH]:\n>";
	std::cin >> this->birthday[BirthdayField::Month];
	std::cout << "~~~Birth [YEAR]:\n>";
	std::cin >> this->birthday[BirthdayField::Year];
	if (!this->valid_birthday())
	{
		std::cout << "~~~Invalid Birthday !~~~" << std::endl;
		return (false);
	}
	std::cout << "~~~Favorite Meal:\n>";
	std::getline(std::cin, this->informations[Field::FavoriteMeal]);
	std::cout << "~~~Underwear Color:\n>";
	std::getline(std::cin, this->informations[Field::UnderwearColor]);
	std::cout << "~~~Darkest Secret:\n>";
	std::getline(std::cin, this->informations[Field::Secret]);
	return (true);
}

void Contact::display_header(void)
{
	
}

void Contact::display(void)
{

}
