/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:18:53 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/06 13:18:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point(void);
	Point(Fixed x, Fixed y);
	Point(const Point &pointObj);
	Point &operator=(Point const &pointObj);
	~Point();

	//! Getters and setters
	Point &getPoint(void);
	Fixed getX(void) const;
	Fixed getY(void) const;

	void setPoint(Fixed &x, Fixed &y);
};

std::ostream &operator<<( std::ostream & output, Point const & input );