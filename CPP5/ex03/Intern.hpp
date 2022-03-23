/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:11:49 by cmariot           #+#    #+#             */
/*   Updated: 2022/03/23 17:18:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{

	public:

		Intern(void);										// Constructeur par default
		Intern(Intern const & copy);						// Constructeur par copie
		
		~Intern(void);										// Destructeur
		
		Intern const &	operator = (Intern const & rhs);	// Surcharge d'opérateur d’affectation

		Form	*makeForm(std::string form_name, std::string target_form);



		class UnknownFormException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Intern exception: I don't kwow how to do that form.");
				}
		} ;

} ;

#endif

