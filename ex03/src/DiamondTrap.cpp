/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:11:37 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:25:44 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("unnamed_clap_name"), _name("unnamed")
{
	_hitPoints = 100;       // de FragTrap
	_energyPoints = 50;     // de ScavTrap
	_attackDamage = 30;     // de FragTrap
	std::cout << "DiamondTrap default constructor called for " << _name
			  << " at [" << this << "]" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = 100;       // de FragTrap
	_energyPoints = 50;     // de ScavTrap
	_attackDamage = 30;     // de FragTrap
	std::cout << "DiamondTrap constructor called for " << _name
			  << " at [" << this << "]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
	: ClapTrap(copy), _name(copy._name)
{
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "DiamondTrap copy constructor called for " << _name
			  << " at [" << this << "]" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);  // herencia virtual ya resuelve todo
		_name = other._name;
	}
	std::cout << "DiamondTrap assignment operator called for " << _name
			  << " at [" << this << "]" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name
			  << " at [" << this << "]" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);  // usar ataque de ScavTrap
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name << " at [" << this << "] says: Who am I?" << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}