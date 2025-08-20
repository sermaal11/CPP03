/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/08/20 15:08:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"


int main(void)
{
	Claptrap generic;

	std::cout << generic.getName() << " has " << generic.getHitPoints()
				<< " hit points, " << generic.getEnergyPoints() << " energy points and "
				<< generic.getAttackDamage() << " attack damage." << std::endl;

	Claptrap copy(generic);
	
	std::cout << copy.getName() << " has " << copy.getHitPoints()
				<< " hit points, " << copy.getEnergyPoints() << " energy points and "
				<< copy.getAttackDamage() << " attack damage." << std::endl;
	
	Claptrap assigment;
	
	assigment = generic;
	std::cout << assigment.getName() << " has " << assigment.getHitPoints()
				<< " hit points, " << assigment.getEnergyPoints() << " energy points and "
				<< assigment.getAttackDamage() << " attack damage." << std::endl;

	Claptrap param("Sergio", 100, 100, 100);
	std::cout << param.getName() << " has " << param.getHitPoints()
				<< " hit points, " << param.getEnergyPoints() << " energy points and "
				<< param.getAttackDamage() << " attack damage." << std::endl;
	
	return 0;
}