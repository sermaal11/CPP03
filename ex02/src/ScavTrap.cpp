/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:32:25 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 09:14:40 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

//OCF

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "Generic Scav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "[SCAVTRAP] Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << CYAN << "[SCAVTRAP] Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << CYAN << "Copy assignment operator called for " << other._name << RESET << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "[SCAVTRAP] Default destructor called" << RESET << std::endl;
}

// Constructor x parametro

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << CYAN << "[SCAVTRAP] Param constructor called" << RESET << std::endl;
}

// Metodos
void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot attack because is dead!"
				<< RESET << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot attack because has no energy points!"
				<< RESET << std::endl;
		return;
	}
	std::cout << GREEN << _name << " is a ScavTrap and "
			<< " attacks to " << target
			<< " causing " << _attackDamage
			<< " points!" << RESET << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot entered gate keeper mode because is dead."
				<< RESET << std::endl;
		return;
	}
	else
	{
	std::cout << MAGENTA << _name
              << " HAS ENTERED GATE KEEPER MODE!" 
              << RESET << std::endl;
	}
}



