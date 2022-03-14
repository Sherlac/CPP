/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:09:33 by cmariot           #+#    #+#             */
/*   Updated: 2022/03/14 16:24:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_fractionalBits = 8;

/***********************************************/
/*            CONSTRUCTEURS/DESTRUCTEURS       */
/***********************************************/

//Constructeur par default
Fixed::Fixed(void) : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//Constructeur par copie
Fixed::Fixed(Fixed const & obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_number = obj.getRawBits();
	return ;
}

//Destructeur par default
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}


/***********************************************/
/*             SURCHARGE D'OPERATEURS          */
/***********************************************/

Fixed &		Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}


/***********************************************/
/*             FONCTIONS MEMBRES               */
/***********************************************/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}
