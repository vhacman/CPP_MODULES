/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:41:51 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

/*HumanA deve ricevere una referenza a Weapon già al momento della costruzione.
Costruttore: richiede name e Weapon& come parametri.*/
class HumanA
{
private:
	std::string	_name;
	Weapon		&_weaponREF;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
