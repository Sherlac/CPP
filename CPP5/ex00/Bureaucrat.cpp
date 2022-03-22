/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:30:53 by cmariot           #+#    #+#             */
/*   Updated: 2022/03/22 11:50:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/***********************************************/
/*            CONSTRUCTEURS/DESTRUCTEURS       */
/***********************************************/

//Constructeur par default
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	//std::cout << "Bureaucrat default constructor called." << std::endl;
	try
	{
		if (grade >= 0 && grade <= 150)
			this->_grade = grade;
		else if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (grade < 0)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException & exception)
	{
		std::cout << exception.what() << std::endl;
		this->_grade = 0;
	}
	catch (Bureaucrat::GradeTooHighException & exception)
	{
		std::cout << exception.what() << std::endl;
		this->_grade = 150;
	}
	return ;
}

//Constructeur par copie
Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	//std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = copy;
	return ;
}

//Destructeur
Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}


/***********************************************/
/*             SURCHARGE D'OPERATEURS          */
/***********************************************/

//Operateur d'affectation (=)
Bureaucrat const &	Bureaucrat::operator = (Bureaucrat const & rhs)
{
	this->_name = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}

//Operateur <<
std::ostream &	operator << (std::ostream & output, Bureaucrat const & rhs)
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (output);
}


/***********************************************/
/*                FONCTIONS MEMBRES            */
/***********************************************/

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade < 150)
			this->_grade += 1;
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException & exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade > 0)
			this->_grade -= 1;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException & exception)
	{
		std::cout << exception.what() << std::endl;
	}
}
