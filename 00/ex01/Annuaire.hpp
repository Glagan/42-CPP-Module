/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:49 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/19 19:11:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_HPP
# define ANNUAIRE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Annuaire
{
private:
	Contact	contacts[8];
	int		amount;
public:
	Annuaire();
	~Annuaire();

	void	show_startup(void);
	void	add_contact(void);
	void	search_contact(void);
	void	show_search_header(void);
};

#endif
