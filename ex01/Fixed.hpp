/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:00:26 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 10:01:31 by antoda-s         ###   ########.fr       */
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
		Fixed(const int pureIntNum);

		// Float constructor
		Fixed(const float pureFloatNum);
		
		//! Copy assignment
		Fixed& operator=(const Fixed& fixedPointObj);

		~Fixed();

		//! Others
		float toFloat(void) const;
		int toInt(void) const;

		//! Getters and setters 
		int getRawBits(void) const;
		void setRawBits(int const pureIntNum);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPointObj);

#endif
