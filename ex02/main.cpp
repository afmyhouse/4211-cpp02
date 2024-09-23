/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:36:52 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/03 11:13:39 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed 			a;
	Fixed	const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	const	c( Fixed( 5.05f ));
	Fixed	const	d( Fixed( 2 ) );
	
	std::cout << "\nTest 01 --------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << "\nTest 02 --------------------" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "\nTest 03 --------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << "\nTest 04 --------------------" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "\nTest 05 --------------------" << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "\nTest 06 --------------------" << std::endl;
	std::cout << b << std::endl;
	
	std::cout << "\nTest 07 --------------------" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "\nTest 08 --------------------" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "\nTest 09 --------------------" << std::endl;
	std::cout << c << std::endl;
	std::cout << "\nTest 10 --------------------" << std::endl;
	std::cout << d << std::endl;
	
	return 0;
}