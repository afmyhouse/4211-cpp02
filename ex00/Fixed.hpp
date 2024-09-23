/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:10:54 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 10:10:57 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int fixedPointNumber;
		static const int fractionalSize = 8;
		
	public:
		//! Constructors and destructor
		// Default constructor
		Fixed();
		// Cpopy constructor
		Fixed(Fixed &fixedPointObj);
		//! Copy assignment Operator or Operator '=' overloading
		Fixed& operator=(Fixed &fixedPointObj);
		// Desctructor
		~Fixed();

		//! Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const pureIntNum);
};

#endif
