/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:58:07 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:17:20 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "../include/ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();                               // constructor por defecto
	FragTrap(const std::string& name);        // constructor con nombre
	FragTrap(const FragTrap& copy);           // constructor de copia
	FragTrap& operator=(const FragTrap& other); // operador de asignación
	~FragTrap();                              // destructor

	void highFivesGuys();                     // método exclusivo
};

#endif