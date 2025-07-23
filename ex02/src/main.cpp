/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:02:37 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"


int main()
{
	std::cout << GREEN << "\n=== Construcción de un FragTrap ===" << RESET << std::endl;
	FragTrap ft("Fragger");

	std::cout << CYAN << "\n=== Prueba de ataque ===" << RESET << std::endl;
	ft.attack("enemigo");

	std::cout << CYAN << "\n=== Prueba de recibir daño ===" << RESET << std::endl;
	ft.takeDamage(42);

	std::cout << CYAN << "\n=== Prueba de reparación ===" << RESET << std::endl;
	ft.beRepaired(25);

	std::cout << YELLOW << "\n=== Petición de high-five ===" << RESET << std::endl;
	ft.highFivesGuys();

	std::cout << GREEN << "\n=== Fin del programa, destrucción en orden inverso ===" << RESET << std::endl;
	return 0;
	return 0;
}