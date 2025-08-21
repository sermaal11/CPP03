/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:15 by sergio            #+#    #+#             */
/*   Updated: 2025/08/21 12:13:07 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	
	public:
		// OCF
		ClapTrap();									// Constructor x defecto
		ClapTrap(const ClapTrap& other);			// Constructor x copia
		ClapTrap& operator=(const ClapTrap& other);	// Operador de asigancion
		~ClapTrap();								// Destructor x defecto

		// Constructor por parametros
		ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
		
		// Getters
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;

		// Metodos
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
