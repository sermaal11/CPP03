/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:59:45 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 09:05:25 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Generic Frag";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "[FRAGTRAP] Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << CYAN << "[FRAGTRAP] Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "[FRAGTRAP] Default destructor called" << RESET << std::endl;
}

// Constructor x parametro

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << CYAN << "[SCAVTRAP] Param constructor called" << RESET << std::endl;
}

// Metodos
void FragTrap::highFivesGuys()
{
	std::cout << MAGENTA << _name
              << " IS WAITING FOR A HIGHFIVE!" 
              << RESET << std::endl;
}
