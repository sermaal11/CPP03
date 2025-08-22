/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:12:58 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 10:15:32 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		//OCF
		DiamondTrap();										// Constructor x defecto
		DiamondTrap(const DiamondTrap& other);				// Constructor x copia
		DiamondTrap& operator=(const DiamondTrap& other);	// Operador de asignacion
		~DiamondTrap();										// Destructor x defecto

		// Constructor x parametros
		DiamondTrap(const std::string& name);

		// Metodos
		void whoAmI();
		using ScavTrap::attack;
};

#endif