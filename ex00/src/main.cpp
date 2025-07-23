/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 18:26:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"


int main(void)
{
	std::cout << GREEN << "\n=== Creación de ClapTraps ===" << RESET << std::endl;
	ClapTrap ct1("R2D2");
	ClapTrap ct2("C3PO");

	std::cout << GREEN << "\n=== Copia por constructor (ct3 copia de ct1) ===" << RESET << std::endl;
	ClapTrap ct3(ct1);

	std::cout << GREEN << "\n=== Asignación: ct3 = ct2 ===" << RESET << std::endl;
	ct3 = ct2;

	std::cout << CYAN << "\n=== Pruebas de ataques ===" << RESET << std::endl;
	ct1.attack("SITH");        // válido
	ct2.attack("DROIDIKA");    // válido
	ct3.attack("JABBA");       // ct3 se comporta como ct2 tras asignación

	std::cout << CYAN << "\n=== Pruebas de recibir daño ===" << RESET << std::endl;
	ct1.takeDamage(4);         // baja HP
	ct2.takeDamage(6);         // baja HP a 4
	ct3.takeDamage(3);         // independiente aunque sea copia

	std::cout << CYAN << "\n=== Pruebas de reparación ===" << RESET << std::endl;
	ct1.beRepaired(5);         // sube HP
	ct2.beRepaired(2);         // sube HP
	ct3.beRepaired(1);         // sube HP

	std::cout << RED << "\n=== Agotar energía de ct2 ===" << RESET << std::endl;
	for (int i = 0; i < 10; ++i)
		ct2.attack("TARGET " + std::to_string(i));  // los últimos deben fallar

	std::cout << RED << "\n=== Reparar sin energía (ct2) ===" << RESET << std::endl;
	ct2.beRepaired(10);  // debería fallar por falta de energía

	std::cout << RED << "\n=== Matar a ct1 y probar acciones ===" << RESET << std::endl;
	ct1.takeDamage(100);   // HP a 0
	ct1.attack("DARK SIDE");   // debería fallar
	ct1.beRepaired(10);        // debería fallar

	std::cout << YELLOW << "\n=== Ataques cruzados y más interacciones ===" << RESET << std::endl;
	ct3.attack("SITH");
	ct3.attack("JABBA");
	ct3.takeDamage(2);
	ct3.beRepaired(3);

	std::cout << GREEN << "\n=== Fin del programa ===" << RESET << std::endl;
	return 0;
}