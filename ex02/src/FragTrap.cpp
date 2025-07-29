/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:59:45 by sergio            #+#    #+#             */
/*   Updated: 2025/07/29 09:23:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("unnamedFrag")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
	: ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called for " << _name 
			  << " at [" << this << "]" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name 
			  << " at [" << this << "]" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " at [" << this << "] requests a high five!"
			  << std::endl;
}