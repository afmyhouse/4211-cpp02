/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:01:05 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 10:12:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->fixedPointNumber = 0;
}

Fixed :: Fixed(const int pureInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = pureInt * (1 << Fixed::fractionalSize);
}

Fixed :: Fixed(const float pureFloat)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = pureFloat * (1 << Fixed::fractionalSize);
}

Fixed :: Fixed(const Fixed& fixedPointObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedPointObj;
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
 
int Fixed :: getRawBits(void) const
{
	return (this->fixedPointNumber);
}
 
void Fixed :: setRawBits(int const pureInt)
{
	this->fixedPointNumber = pureInt;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->fixedPointNumber / (float)(1 << Fixed::fractionalSize));
}

int Fixed :: toInt(void) const
{
	return (this->fixedPointNumber >> Fixed::fractionalSize);
}

Fixed& Fixed :: operator=(const Fixed& fixedPointObj)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &fixedPointObj)
		return (*this);
	this->fixedPointNumber = fixedPointObj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPointObj)
{
	out << fixedPointObj.toFloat();
	return (out);
}
