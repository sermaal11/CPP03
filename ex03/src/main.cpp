/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 10:16:19 by sergio           ###   ########.fr       */
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

	// Edge cases
	// 1) Atacar sin energía (drenamos los 50 EP primero para DiamondTrap)
	DiamondTrap noEnergy("NoEnergy");
	std::cout << "[Edge] Attack with 0 energy" << std::endl;
	for (int i = 0; i < 50; ++i) noEnergy.attack("Dummy"); // EP -> 0
	std::cout << noEnergy.getName() << " has " << noEnergy.getHitPoints()
			  << " hit points, " << noEnergy.getEnergyPoints() << " energy points and "
			  << noEnergy.getAttackDamage() << " attack damage." << std::endl;
	noEnergy.attack("OutOfJuice");                           // debe negarse

	// 2) Reparar sin energía (drenamos energía y luego intentamos reparar)
	DiamondTrap noEnergyRepair("NoEnergyRepair");
	std::cout << "[Edge] Repair with 0 energy" << std::endl;
	for (int i = 0; i < 50; ++i) noEnergyRepair.attack("Air"); // EP -> 0
	std::cout << noEnergyRepair.getName() << " has " << noEnergyRepair.getHitPoints()
			  << " hit points, " << noEnergyRepair.getEnergyPoints() << " energy points and "
			  << noEnergyRepair.getAttackDamage() << " attack damage." << std::endl;
	noEnergyRepair.beRepaired(3);                               // debe negarse

	// 3) Muerte y acciones posteriores
	DiamondTrap doomed("Doomed");
	std::cout << "[Edge] Fatal damage then actions" << std::endl;
	doomed.takeDamage(150);           // HP -> 0
	doomed.attack("Dummy");           // debe negarse (muerto)
	doomed.beRepaired(10);            // debe negarse (muerto)
	doomed.highFivesGuys();           // debe negarse o avisar (muerto)
	doomed.guardGate();               // debe negarse (muerto)
	doomed.whoAmI();                  // específico de DiamondTrap
	std::cout << doomed.getName() << " has " << doomed.getHitPoints()
			  << " hit points, " << doomed.getEnergyPoints() << " energy points and "
			  << doomed.getAttackDamage() << " attack damage." << std::endl;

	// 4) Daño exacto igual a HP (DiamondTrap empieza con 100)
	DiamondTrap boundary("Boundary");
	std::cout << "[Edge] Exact lethal damage" << std::endl;
	boundary.takeDamage(100);        // HP -> 0 exacto
	std::cout << boundary.getName() << " HP: "
			  << boundary.getHitPoints() << std::endl;

	// 5) Agotar energía atacando (y un ataque extra)
	DiamondTrap spam("Spammer");
	std::cout << "[Edge] Drain energy by attacking" << std::endl;
	for (int i = 0; i < 50; ++i) spam.attack("A"); // EP -> 0
	spam.attack("B");                               // debe negarse

	// 6) Autoasignación
	DiamondTrap self("Selfie");
	std::cout << "[Edge] Self-assignment" << std::endl;
	DiamondTrap& alias = self; // evitar -Wself-assign-overloaded
	self = alias;
	std::cout << self.getName() << " HP: " << self.getHitPoints()
			  << " EN: " << self.getEnergyPoints()
			  << " AD: " << self.getAttackDamage() << std::endl;

	// 7) Copia y mutación del original (la copia no cambia)
	DiamondTrap original("Original");
	DiamondTrap clone(original);
	std::cout << "[Edge] Copy then mutate original" << std::endl;
	original.takeDamage(35);
	std::cout << "Original HP: " << original.getHitPoints()
			  << " | Clone HP: " << clone.getHitPoints() << std::endl;

	// 8) Reparación grande (si no hay tope máximo en tu lógica)
	DiamondTrap healer("Healer");
	std::cout << "[Edge] Huge repair" << std::endl;
	healer.takeDamage(99);           // HP -> 1
	healer.beRepaired(1000);         // aumentará mucho si no impones cap
	std::cout << healer.getName() << " HP after huge repair: "
			  << healer.getHitPoints() << std::endl;

	// 9) Atacar con HP == 0 pero con energía > 0
	DiamondTrap ghost("Ghost");
	std::cout << "[Edge] Attack while dead (HP=0)" << std::endl;
	ghost.takeDamage(100);           // HP -> 0 (EP sigue en 50)
	ghost.attack("LivingTarget");    // debe negarse (muerto)

	// 10) whoAmI y highFivesGuys en estados límite
	DiamondTrap five("HighFiveDude");
	std::cout << "[Edge] Diamond methods alive vs dead" << std::endl;
	five.highFivesGuys();            // debe pedir high five (vivo)
	five.guardGate();                // debe funcionar (vivo)
	five.whoAmI();                   // debe mostrar nombres (vivo)
	five.takeDamage(200);            // lo matamos
	five.highFivesGuys();            // debe negarse (muerto)
	five.guardGate();                // debe negarse (muerto)
	five.whoAmI();                   // específico test para DiamondTrap muerto
	return 0;
}