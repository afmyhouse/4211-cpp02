/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 08:30:08 by ncarvalh          #+#    #+#             */
/*   Updated: 2024/05/07 10:17:06 by antoda-s         ###   ########.fr       */
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

Fixed :: Fixed(const float floatPointNum)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = floatPointNum * (1 << Fixed::fractionalSize);
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
 
void Fixed :: setRawBits(int const pureIntNum)
{
	this->fixedPointNumber = pureIntNum;
}

float Fixed :: toFloat(void) const
{
	return ((float)this->fixedPointNumber / (float)(1 << Fixed::fractionalSize));
}

int Fixed :: toInt(void) const
{
	return (this->fixedPointNumber >> Fixed::fractionalSize);
}

/* operators functions overload*/
Fixed& Fixed :: operator=(const Fixed& fixedPointObj)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &fixedPointObj)
		return (*this);
	this->fixedPointNumber = fixedPointObj.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixedPointObj) const {
  return (this->toFloat() > fixedPointObj.toFloat());
}

bool Fixed::operator<(const Fixed &fixedPointObj) const {
  return (this->toFloat() < fixedPointObj.toFloat());
}

bool Fixed::operator>=(const Fixed &fixedPointObj) const {
  return (this->toFloat() >= fixedPointObj.toFloat());
}

bool Fixed::operator<=(const Fixed &fixedPointObj) const {
  return (this->toFloat() <= fixedPointObj.toFloat());
}

bool Fixed::operator==(const Fixed &fixedPointObj) const {
  return (this->toFloat() == fixedPointObj.toFloat());
}

bool Fixed::operator!=(const Fixed &fixedPointObj) const {
  return (this->toFloat() != fixedPointObj.toFloat());
}

Fixed Fixed::operator+(const Fixed &fixedPointObj) {
  return (this->toFloat() + fixedPointObj.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixedPointObj) {
  return (this->toFloat() - fixedPointObj.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixedPointObj) {
  return (this->toFloat() * fixedPointObj.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixedPointObj) {
  return (this->toFloat() / fixedPointObj.toFloat());
}

Fixed Fixed::operator++(void) {
	this->fixedPointNumber++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed copy(*this);
	
	++(*this);
	return (copy);
}

Fixed Fixed::operator--(void) {
	this->fixedPointNumber--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed copy(*this);
	
	--(*this);
	return (copy);
}

Fixed &Fixed::min(Fixed& fixedPointObj1, Fixed& fixedPointObj2) {
	return (fixedPointObj1 < fixedPointObj2 ? fixedPointObj1 : fixedPointObj2);
}

const Fixed &Fixed::min(const Fixed &fixedPointObj1, const Fixed &fixedPointObj2) {
	return (fixedPointObj1 < fixedPointObj2 ? fixedPointObj1 : fixedPointObj2);
}

Fixed &Fixed::max(Fixed &fixedPointObj1, Fixed &fixedPointObj2) {
	return (fixedPointObj1 > fixedPointObj2 ? fixedPointObj1 : fixedPointObj2);
}

const Fixed &Fixed::max(const Fixed &fixedPointObj1, const Fixed &fixedPointObj2) {
	return (fixedPointObj1 > fixedPointObj2 ? fixedPointObj1 : fixedPointObj2);
}

std::ostream& operator<<(std::ostream &result, const Fixed &fixedPointObj)
{
	result << fixedPointObj.toFloat();
	return (result);
}