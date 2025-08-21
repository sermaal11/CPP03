/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:32:25 by sergio            #+#    #+#             */
/*   Updated: 2025/08/21 14:17:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "Generic Scav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "[SCAVTRAP] Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
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
	std::cout << RED << "[SCAVTRAP] Default destructor called" << RESET << std::endl;
}

