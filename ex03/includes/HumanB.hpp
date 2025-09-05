/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:09 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:37:51 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

/*HumanB may not always have a weapon.
Quindi deve avere un puntatore a Weapon (inizialmente nullo).
Metodo aggiuntivo: setWeapon(Weapon& weapon) per assegnare l’arma in un secondo momento.
attack() deve verificare se _weapon è nullo prima di accedere.*/
class HumanB
{
private:
	std::string	_name;
	Weapon		*_weaponPTR;

public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif
