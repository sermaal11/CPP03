/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:58:07 by sergio            #+#    #+#             */
/*   Updated: 2025/08/22 09:24:18 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "../include/ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// OCF
		FragTrap();									// Constructor x defecto
		FragTrap(const FragTrap& other);			// Constructor x copia
		FragTrap& operator=(const FragTrap& other);	// Operador de asigancion
		~FragTrap();								// Destructor x defecto

		// Constructor x parametro
		FragTrap(const std::string& name);
		
		//Metodos
		void highFivesGuys(void);
};

#endif