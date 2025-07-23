/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:12:58 by sergio            #+#    #+#             */
/*   Updated: 2025/07/23 20:15:11 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "../include/FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;  // mismo nombre que en ClapTrap

public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string& target); // usar el de ScavTrap
};

#endif