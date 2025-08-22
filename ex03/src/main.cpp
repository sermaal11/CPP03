/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 10:36:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main()
{
	DiamondTrap generic;
	std::cout << generic.getName() << " has " << generic.getHitPoints()
				<< " hit points, " << generic.getEnergyPoints() << " energy points and "
				<< generic.getAttackDamage() << " attack damage." << std::endl;

	DiamondTrap copy(generic);
	std::cout << copy.getName() << " has " << copy.getHitPoints()
				<< " hit points, " << copy.getEnergyPoints() << " energy points and "
				<< copy.getAttackDamage() << " attack damage." << std::endl;

	DiamondTrap assigment;
	assigment = generic;
	std::cout << assigment.getName() << " has " << assigment.getHitPoints()
				<< " hit points, " << assigment.getEnergyPoints() << " energy points and "
				<< assigment.getAttackDamage() << " attack damage." << std::endl;

	DiamondTrap param("C3PO");
	std::cout << param.getName() << " has " << param.getHitPoints()
				<< " hit points, " << param.getEnergyPoints() << " energy points and "
				<< param.getAttackDamage() << " attack damage." << std::endl;

	ClapTrap terminator("T-800", 10, 10, 0);
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;
	DiamondTrap droide("R2D2");
	std::cout << droide.getName() << " has " << droide.getHitPoints()
				<< " hit points, " << droide.getEnergyPoints() << " energy points and "
				<< droide.getAttackDamage() << " attack damage." << std::endl;
	terminator.attack("T-1000");
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;
	droide.attack("Jabba the Hut");
	std::cout << droide.getName() << " has " << droide.getHitPoints()
				<< " hit points, " << droide.getEnergyPoints() << " energy points and "
				<< droide.getAttackDamage() << " attack damage." << std::endl;
	droide.takeDamage(3);
	std::cout << droide.getName() << " has " << droide.getHitPoints()
				<< " hit points, " << droide.getEnergyPoints() << " energy points and "
				<< droide.getAttackDamage() << " attack damage." << std::endl;
	droide.beRepaired(5);
	std::cout << droide.getName() << " has " << droide.getHitPoints()
				<< " hit points, " << droide.getEnergyPoints() << " energy points and "
				<< droide.getAttackDamage() << " attack damage." << std::endl;
	droide.highFivesGuys();
	droide.guardGate();
	droide.whoAmI();

	return 0;
}