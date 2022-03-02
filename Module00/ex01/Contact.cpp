/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:36:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/02/28 19:10:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "Constructeur Contact" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructeur Contact" << std::endl;
	return ;
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) :
	_first_name(fn), _last_name(ln), _nick_name(nn), _phone_number(pn), _darkest_secret(ds)
{
	return ;
}
