/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:28 by sergio            #+#    #+#             */
/*   Updated: 2025/08/21 11:50:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

// Orthodox Canonichl Form

Claptrap::Claptrap() 
	:	_name("Default Claptrap"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout << CYAN << "[CLAPTRAP] Default constructor called" << RESET << std::endl;
}

Claptrap::Claptrap(const Claptrap& other)
	:	_name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage)
{
	std::cout << CYAN << "[CLAPTRAP] Copy constructor called" << RESET << std::endl;
}

Claptrap& Claptrap::operator=(const Claptrap& other)
{
	std::cout << CYAN << "Copy assignment operator called for " << other._name << RESET << std::endl;
	
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

Claptrap::~Claptrap()
{
	std::cout << RED << "[CLAPTRAP] Default destructor called" << RESET << std::endl;
}

// Constructor x parametros

Claptrap::Claptrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
	:	_name(name),
		_hitPoints(hitPoints),
		_energyPoints(energyPoints),
		_attackDamage(attackDamage)
{
	std::cout << CYAN << "[CLAPTRAP] Param constructor called" << RESET << std::endl;
}
		
// Getters

std::string Claptrap::getName() const
{
	return _name;
}

int Claptrap::getHitPoints() const
{
	return _hitPoints;
}

int Claptrap::getEnergyPoints() const
{
	return _energyPoints;
}

int Claptrap::getAttackDamage() const
{
	return _attackDamage;
}

// Metodos
void Claptrap::attack(const std::string& target)
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
	std::cout << GREEN << _name
			<< " attacks to " << target
			<< " causing " << _attackDamage
			<< " points!" << RESET << std::endl;
	_energyPoints--;
	return;
}

void Claptrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot take damage because is dead!"
				<< RESET << std::endl;
		return;
	}
	std::cout << GREEN << _name
			<< " receives " << amount
			<< " points of damage! " 
			<< RESET << std::endl;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;
	return;
}

void Claptrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot be repaired because is dead!"
				<< RESET << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << RED << _name 
				<< " cannot be repaired because has no energy points!"
				<< RESET << std::endl;
		return;
	}
	std::cout << GREEN << _name
			<< " repairs himself " << amount
			<< " hit points! " 
			<< RESET << std::endl;
	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	return;
}
