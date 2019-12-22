/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:07:11 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:59:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include <iomanip>
# include <string>

class Brain
{
private:
	int	neurones;
public:
	Brain();
	virtual ~Brain();

	int getNeurones(void) const;
	std::string identify(void) const;
};

#endif
