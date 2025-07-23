/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:43:15 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 18:56:21 by sergio           ###   ########.fr       */
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
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();									//Constructor x defecto
		ClapTrap(const std::string& name);			//Constructor x parametros
		ClapTrap(const ClapTrap& copy);				//Constructor x copia
		ClapTrap& operator=(const ClapTrap& other);	//Operador de asigacion
		~ClapTrap();								//Destructor x defecto

 		void attack(const std::string& target);
 		void takeDamage(unsigned int amount);
 		void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
