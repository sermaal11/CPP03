/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:19:53 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main()
{
	std::cout << GREEN << "\n=== Creación de un DiamondTrap ===" << RESET << std::endl;
	DiamondTrap dt("Vader");

	std::cout << CYAN << "\n=== Prueba de ataque ===" << RESET << std::endl;
	dt.attack("Jedi");

	std::cout << CYAN << "\n=== Prueba de daño y reparación ===" << RESET << std::endl;
	dt.takeDamage(40);
	dt.beRepaired(25);

	std::cout << YELLOW << "\n=== Prueba de whoAmI() ===" << RESET << std::endl;
	dt.whoAmI();

	std::cout << RED << "\n=== Fin del programa, destrucción ===" << RESET << std::endl;
	return 0;
}