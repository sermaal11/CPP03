/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:28 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 18:25:43 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "Unnamend";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap default constructor called for " << _name << " at [" << this << "]" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap constructor called for " << _name << " at [" << this << "]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
	:	_name(copy._name),
		_hitPoints(copy._hitPoints),
		_energyPoints(copy._energyPoints),
		_attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << _name << " at [" << this << "]" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << _name << " at [" << this << "]" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << " at [" << this << "]" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " at [" << this << "]" 
				  << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " at [" << this << "]" 
				  <<  " has no energy left to attack." << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " at [" << this << "]" << " attacks " 
			  << target << ", causing " << _attackDamage << " points of damage!"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " at [" << this << "]" << " is already dead." << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;
	std::cout << "ClapTrap " << _name << " at [" << this << "]" << " takes " << amount
			  << " points of damage. Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " at [" << this << "]" << " is dead and cannot be repaired." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " at [" << this << "]" << " has no energy left to repair." << std::endl;
		return;
	}
	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " at [" << this << "]" << " repairs itself for " << amount
			  << " HP. Current HP: " << _hitPoints << ", Energy: "
			  << _energyPoints << std::endl;
}