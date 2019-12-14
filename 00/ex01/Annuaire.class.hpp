/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:49 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/14 17:53:39 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_CLASS_HPP
# define ANNUAIRE_CLASS_HPP

# include <iostream>
# include <iomanip>
# include <string>
#include "Contact.class.hpp"

class Annuaire
{
private:
	Contact	contacts[8];
	int		amount;
public:
	Annuaire();
	~Annuaire();

	void	show_startup(void);
	void	show_help(void);
	void	add_contact(void);
	void	search_contact(void);
	void	show_search_header(void);
};

#endif
