/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:19:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/20 17:59:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <cstddef>
# include "ISquad.hpp"

class Squad: public ISquad
{
private:
	int count;
	ISpaceMarine **units;
public:
	Squad();
	Squad(Squad const &other);
	~Squad();

	Squad &operator=(Squad const &other);

	int getCount(void) const;
	ISpaceMarine *getUnit(int index) const;
	int push(ISpaceMarine *unit);
};

#endif
