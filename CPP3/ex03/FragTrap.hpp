/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:19:29 by cmariot           #+#    #+#             */
/*   Updated: 2022/03/18 16:07:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap : virtual public ClapTrap
{

	public:

		FragTrap(void);											// Constructeur par default
		FragTrap(std::string name);								// Constructeur par nom
		FragTrap(FragTrap const & copy);						// Constructeur par copie
		~FragTrap(void);										// Destructeur
		FragTrap const &	operator = (FragTrap const & rhs);	// Surcharge d'opérateur d’affectation

		void attack(const std::string & target);				// Surcharge de la fonction membre heritee
		void highFivesGuys(void) const;							// Fonction membre specifique a la classe

		void	display_specs(void) const;

} ;

#endif
