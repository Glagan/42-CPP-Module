/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KoalaSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:26:32 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:56:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"

class KoalaSteroid: public IAsteroid
{
private:
	std::string name;
public:
	KoalaSteroid();
	KoalaSteroid(std::string const &name);
	KoalaSteroid(KoalaSteroid const &other);
	virtual ~KoalaSteroid();

	KoalaSteroid &operator=(KoalaSteroid const &other);

	std::string getName(void) const;

	std::string beMined(DeepCoreMiner *laser) const;
	std::string beMined(StripMiner *laser) const;
};

#endif
