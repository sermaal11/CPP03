/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:32:55 by sergio            #+#    #+#             */
/*   Updated: 2025/08/21 14:08:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
	public:
		// OCF
		ScavTrap();									// Constructor x defecto
		ScavTrap(const ScavTrap& other);			// Constructor x copia
		ScavTrap& operator=(const ScavTrap& other);	// Operador de asigancion
		~ScavTrap();								// Destructor x defecto
};

#endif