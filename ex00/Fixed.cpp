/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:09:58 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 10:09:59 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedPointNumber = 0;
}

Fixed :: Fixed(Fixed& fixedPointObj)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = fixedPointObj;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed :: operator=(Fixed& fixedPointObj)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &fixedPointObj)
		return (*this);
	this->fixedPointNumber = fixedPointObj.getRawBits();
	return (*this);
}
 
int Fixed :: getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}
 
void Fixed :: setRawBits(int const pureInt)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumber = pureInt;
}
