/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:32:25 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:30:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	(void)_name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << _name 
			<< " at [" << this << "]" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
{
	(void)name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
	:	ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) 
		ClapTrap::operator=(other); // copiar base
	std::cout << "ScavTrap assignment operator called for " << _name 
			  << " at [" << this << "]" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0) 
	{
		std::cout << "ScavTrap " << _name 
				  <<  " at [" << this << "]" <<" is dead and cannot attack."
				  << std::endl;
		return;
	}
	if (_energyPoints == 0) 
	{
		std::cout << "ScavTrap " << _name 
				  <<  " at [" << this << "]" << " has no energy left to attack."
				  << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name 
			  << " at [" << this << "]" << " fiercely attacks " << target
			  << ", dealing " << _attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name 
			  << " at [" << this << "]" << " has entered Gate Keeper mode." 
			  << std::endl;
}


