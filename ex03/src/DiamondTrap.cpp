/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:11:37 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 10:17:03 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

//OCF

DiamondTrap::DiamondTrap() 
	: ClapTrap(), ScavTrap(), FragTrap(), _name("Generic Diamond")
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << CYAN << "[DIAMONDTRAP] Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	_hitPoints    = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << CYAN << "[DIAMONDTRAP] Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << CYAN << "[DIAMONDTRAP] Copy assignment operator called" << RESET << std::endl;

    if (this != &other)
	{
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
        _hitPoints    = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << CYAN << "[DIAMONDTRAP] Default destructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
	: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;		// 100 (de FragTrap)
	_energyPoints = ScavTrap::_energyPoints;	// 50 (de ScavTrap)
	_attackDamage = FragTrap::_attackDamage;	// 30 (de FragTrap)
	std::cout << CYAN << "[DIAMONDTRAP] Parametric constructor called for " << _name << RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << CYAN << "DiamondTrap name: " << _name 
			  << " | ClapTrap name: " << ClapTrap::_name << RESET << std::endl;
}

