/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:21 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 19:40:55 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"


int main()
{
	std::cout << GREEN << "\n=== Construcción de un ScavTrap ===" << RESET << std::endl;
	ScavTrap st("Scavy");

	std::cout << CYAN << "\n=== Prueba de ataque ===" << RESET << std::endl;
	st.attack("Intruder");

	std::cout << CYAN << "\n=== Prueba de recibir daño ===" << RESET << std::endl;
	st.takeDamage(30);

	std::cout << CYAN << "\n=== Prueba de reparación ===" << RESET << std::endl;
	st.beRepaired(20);

	std::cout << YELLOW << "\n=== Activar modo guardián ===" << RESET << std::endl;
	st.guardGate();

	std::cout << GREEN << "\n=== Fin del programa, destrucción en orden inverso ===" << RESET << std::endl;
	return 0;
}