/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:30:53 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/12 11:15:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/***********************************************/
/*            CONSTRUCTEURS/DESTRUCTEURS       */
/***********************************************/

//Constructeur par default
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called." << std::endl;
	return ;
}

//Constructeur par name et grade
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	//std::cout << "Bureaucrat name and grade constructor called." << std::endl;
	try
	{
		if (grade >= 1 && grade <= 150)
			_grade = grade;
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooLowException & exception)
	{
		std::cout << exception.what() << std::endl;
		_grade = 150;
	}
	catch (Bureaucrat::GradeTooHighException & exception)
	{
		std::cout << exception.what() << std::endl;
		_grade = 1;
	}
	return ;
}

//Constructeur par copie
Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(getGrade())
{
	//std::cout << "Bureaucrat copy constructor called." << std::endl;
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
	_grade = rhs.getGrade();
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
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (_grade > 1)
			_grade -= 1;
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
		if (_grade < 150)
			_grade += 1;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException & exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form *form) const
{
	if (form->getSignature() == 1)
		std::cout << getName() << " couldn’t sign "  << form->getName() << ", it's already signed." << std::endl;
	else if (getGrade() <= form->getSignatureGrade())
	{
		form->setSignature();
		std::cout << getName() << " signed "  << form->getName() << std::endl;
	}
	else if (getGrade() > form->getSignatureGrade())
		std::cout << getName() << " couldn’t sign "  << form->getName() << ", grade too low." << std::endl;
}

void	Bureaucrat::executeForm(Form const & form)
{
	if (form.makeVerif(this->_grade, form.getExecutionGrade()) == 0)
	{
		Bureaucrat & thisRef = *this;
		form.execute(thisRef);
		std::cout << this->getName() <<  " executed " << form.getName() << std::endl;
	}
}
