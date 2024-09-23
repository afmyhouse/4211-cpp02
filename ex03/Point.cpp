/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:27:20 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/06 22:25:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {
	// std::cout << "Default Point constructor called." << std::endl;
}

Point :: Point(Fixed px, Fixed py) : x(px), y(py){
	// std::cout << "Initial settings constructor called" << std::endl;
}

Point::Point(const Point &pointObj) : x(pointObj.x), y(pointObj.y) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point :: operator=(Point const &pointObj) {
	if (this == &pointObj)
		return (*this);
	(Fixed) this->x = pointObj.getX();
	(Fixed) this->y = pointObj.getY();
	// std::cout << "Point > Copy assignament constructor" << std::endl;
	return *this;
}

Point::~Point() {
	// std::cout << "Point Desctructor " << std::endl;
}

Point &Point::getPoint(void) {
	return (*this);
}

void Point::setPoint( Fixed &px, Fixed &py) {
	(Fixed) this->x = px;
	(Fixed) this->y = py;
}

Fixed Point::getX(void) const {
	return ((Fixed) this->x);
}

Fixed Point::getY(void) const {
	return this->y;
}

std::ostream &operator<<(std::ostream &output, Point const &input ) {
	output << "Value X = " << input.getX() << " | Value Y = " << input.getY();
	return output;
}