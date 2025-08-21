/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/08/21 12:12:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"


int main(void)
{
	ClapTrap generic;

	std::cout << generic.getName() << " has " << generic.getHitPoints()
				<< " hit points, " << generic.getEnergyPoints() << " energy points and "
				<< generic.getAttackDamage() << " attack damage." << std::endl;

	ClapTrap copy(generic);
	
	std::cout << copy.getName() << " has " << copy.getHitPoints()
				<< " hit points, " << copy.getEnergyPoints() << " energy points and "
				<< copy.getAttackDamage() << " attack damage." << std::endl;
	
	ClapTrap assigment;
	
	assigment = generic;
	std::cout << assigment.getName() << " has " << assigment.getHitPoints()
				<< " hit points, " << assigment.getEnergyPoints() << " energy points and "
				<< assigment.getAttackDamage() << " attack damage." << std::endl;

	ClapTrap param("Sergio", 100, 100, 100);
	std::cout << param.getName() << " has " << param.getHitPoints()
				<< " hit points, " << param.getEnergyPoints() << " energy points and "
				<< param.getAttackDamage() << " attack damage." << std::endl;
	
	ClapTrap terminator("T-800", 10, 10, 0);
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;
	terminator.attack("T-1000");
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;
	terminator.takeDamage(3);
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;
	terminator.beRepaired(5);
	std::cout << terminator.getName() << " has " << terminator.getHitPoints()
				<< " hit points, " << terminator.getEnergyPoints() << " energy points and "
				<< terminator.getAttackDamage() << " attack damage." << std::endl;

	// Edge cases
	// 1) Atacar sin energía
    ClapTrap noEnergy("NoEnergy", 10, 0, 5);
    std::cout << "[Edge] Attack with 0 energy" << std::endl;
    noEnergy.attack("Dummy");

    // 2) Reparar sin energía
    ClapTrap noEnergyRepair("NoEnergyRepair", 5, 0, 1);
    std::cout << "[Edge] Repair with 0 energy" << std::endl;
    noEnergyRepair.beRepaired(3);

    // 3) Muerte y acciones posteriores
    ClapTrap doomed("Doomed", 2, 5, 1);
    std::cout << "[Edge] Fatal damage then actions" << std::endl;
    doomed.takeDamage(5);           // HP -> 0
    doomed.attack("Dummy");         // should refuse
    doomed.beRepaired(10);          // should refuse

    // 4) Daño exacto igual a HP 
    ClapTrap boundary("Boundary", 7, 5, 2);
    std::cout << "[Edge] Exact lethal damage" << std::endl;
    boundary.takeDamage(7);         // HP -> 0 exacto
    std::cout << boundary.getName() << " HP: "
              << boundary.getHitPoints() << std::endl;

    // 5) Agotar energía atacando
    ClapTrap spam("Spammer", 10, 2, 1);
    std::cout << "[Edge] Drain energy by attacking" << std::endl;
    spam.attack("A");               // EP -> 1
    spam.attack("B");               // EP -> 0
    spam.attack("C");               // should refuse

    // 6) Autoasignación
    ClapTrap self("Selfie", 10, 10, 10);
    std::cout << "[Edge] Self-assignment" << std::endl;
    ClapTrap& alias = self;
	self = alias;
    std::cout << self.getName() << " HP: " << self.getHitPoints()
              << " EN: " << self.getEnergyPoints()
              << " AD: " << self.getAttackDamage() << std::endl;

    // 7) Copia y mutación del original
    ClapTrap original("Original", 10, 10, 3);
    ClapTrap clone(original);
    std::cout << "[Edge] Copy then mutate original" << std::endl;
    original.takeDamage(5);
    std::cout << "Original HP: " << original.getHitPoints()
              << " | Clone HP: " << clone.getHitPoints() << std::endl;

    // 8) Reparación grande
    ClapTrap healer("Healer", 1, 3, 0);
    std::cout << "[Edge] Huge repair" << std::endl;
    healer.beRepaired(1000);
    std::cout << healer.getName() << " HP after huge repair: "
              << healer.getHitPoints() << std::endl;

    // 9) Atacar con HP == 0 pero con energía > 0
    ClapTrap ghost("Ghost", 0, 5, 10);
    std::cout << "[Edge] Attack while dead (HP=0)" << std::endl;
    ghost.attack("LivingTarget");
	return 0;
}
