/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroKreog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:27:17 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/22 17:56:51 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include "IAsteroid.hpp"

class AsteroKreog: public IAsteroid
{
private:
	std::string name;
public:
	AsteroKreog();
	AsteroKreog(std::string const &name);
	AsteroKreog(AsteroKreog const &other);
	virtual ~AsteroKreog();

	AsteroKreog &operator=(AsteroKreog const &other);

	std::string getName(void) const;

	std::string beMined(DeepCoreMiner *laser) const;
	std::string beMined(StripMiner *laser) const;
};

#endif
