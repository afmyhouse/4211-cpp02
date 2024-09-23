/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:06:29 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 10:06:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed
{
	private:
		int fixedPointNumber;
		static const int fractionalSize = 8;
		
	public:
		//! Constructors and destructors
		// Default constructor
		Fixed();

		// Copy constructor
		Fixed(const Fixed &fixedPointObj);
		
		// Int constructor
		Fixed(const int pureInt);

		// Float constructor
		Fixed(const float floatPointNum);
		Fixed(const double doublePointNum);
		
		//! Copy assignment & operators overloading
		Fixed& operator=(const Fixed& fixedPointObj);
		bool operator>(const Fixed& fixedPointObj) const;
		bool operator<(const Fixed& fixedPointObj) const;
		bool operator>=(const Fixed& fixedPointObj) const;
		bool operator<=(const Fixed& fixedPointObj) const;
		bool operator==(const Fixed& fixedPointObj) const;
		bool operator!=(const Fixed& fixedPointObj) const;
		Fixed operator+(const Fixed& fixedPointObj);
		Fixed operator-(const Fixed& fixedPointObj);
		Fixed operator*(const Fixed& fixedPointObj);
		Fixed operator/(const Fixed& fixedPointObj);
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		~Fixed();

		//! Others
		float toFloat(void) const;
		int toInt(void) const;

		//! Getters and setters 
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// min and max
		static Fixed& min(Fixed& fixedPointObj1, Fixed& fixedPointObj2);
		static Fixed& max(Fixed& fixedPointObj1, Fixed& fixedPointObj2);
		static const Fixed& min(const Fixed& fixedPointObj1, const Fixed& fixedPointObj2);
		static const Fixed& max(const Fixed& fixedPointObj1, const Fixed& fixedPointObj2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPointObj);

#endif
