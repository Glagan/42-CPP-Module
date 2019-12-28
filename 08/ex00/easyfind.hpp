/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:08:02 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/28 16:39:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
int easyfind(T container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return (*it);
}

#endif
