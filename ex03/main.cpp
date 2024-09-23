/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:36:52 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 11:23:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point &p, Point &A, Point &B, Point &C);

void testPointInsideTriangle(Point &P, Point &A, Point &B, Point &C) {

	std::cout << P.getX() << "," << P.getY() << ")" << std::endl;
	if (bsp(P, A, B, C))
		std::cout << "Point INSIDE  Triangle ABC" << std::endl;
	else
		std::cout << "Point OUTSIDE Triangle ABC" << std::endl;
}

int main( void ) {

	// Point	A(3.0f, 4.0f);
	// Point	B(8,4);
	// Point	C(2,-2);

	Point	A(0.0f,0.0f);
	Point	B(0.0f,8.0f);
	Point	C(8.0f,0.0f);

	std::cout << "Triangle A(" << A.getX() << ", " << A.getY() << ")";
	std::cout <<        ", B(" << B.getX() << ", " << B.getY() << ")";
	std::cout <<        ", C(" << C.getX() << ", " << C.getY() << ")" << std::endl;

	Point Pd(float(4), float(3)); // Point inside the triangle
	Point Pe(float(4), float(4)); // Point in the border of the triangle
	Point Pf(float(4.0183),
			float(3.9)); // Point inside the triangle close to the border
	Point Pg(float(4.00389),
			float(4.4035)); // Point outside the triangle close to the border
	Point Ph(float(-4.00389), float(-4.4035)); // Point outside the triangle

	std::cout << "\nPoint Pd(";
	testPointInsideTriangle(Pd, A, B, C);
	std::cout << "\nPoint Pe(";
	testPointInsideTriangle(Pe, A, B, C);
	std::cout << "\nPoint Pf(";
	testPointInsideTriangle(Pf, A, B, C);
	std::cout << "\nPoint Pg(";
	testPointInsideTriangle(Pg, A, B, C);
	std::cout << "\nPoint Ph(";
	testPointInsideTriangle(Ph, A, B, C);

	Point Pi(float(0), float(0)); // Point is on the vertex of the triangle
	Point Pj(float(0), float(8)); // Point is on the vertex of the triangle
	Point Pk(float(8), float(0)); // Point is on the vertex of the triangle
	std::cout << "\nPoint Pi(";
	testPointInsideTriangle(Pi, A, B, C);
	std::cout << "\nPoint Pj(";
	testPointInsideTriangle(Pj, A, B, C);
	std::cout << "\nPoint Pk(";
	testPointInsideTriangle(Pk, A, B, C);

	Point Pl(float(0), float(4)); // Point is on the edge of the triangle
	Point Pm(float(4), float(0)); // Point is on the edge of the triangle
	Point Pn(float(4), float(4)); // Point is on the edge of the triangle
	std::cout << "\nPoint Pl(";
	testPointInsideTriangle(Pl, A, B, C);
	std::cout << "\nPoint Pm(";
	testPointInsideTriangle(Pm, A, B, C);
	std::cout << "\nPoint Pn(";
	testPointInsideTriangle(Pn, A, B, C);
}
