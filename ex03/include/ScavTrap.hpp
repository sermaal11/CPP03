/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:32:55 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:17:43 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();									//Constructor por defecto
		ScavTrap(const std::string& name);			//Constructor x parametros
		ScavTrap(const ScavTrap& other);			//Constructor x copia
		ScavTrap& operator=(const ScavTrap& other);	//Operador de asignacion
		~ScavTrap();								//Destructor x defecto

		void guardGate();

		void attack(const std::string& target);
};

#endif