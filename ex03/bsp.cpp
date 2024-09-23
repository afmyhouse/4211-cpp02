/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:25:03 by antoda-s          #+#    #+#             */
/*   Updated: 2024/05/07 11:27:03 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Point.hpp"
#include <iostream>

/// @brief 		Calculates the area of triangle with coordinates A B C
/// @param A 	Triangle vertice A
/// @param B 	Triangle vertice B
/// @param C 	Triangle vertice C
/// @return 	Area (Fixed type)
Fixed areaOfTriangle(Point A, Point B, Point C) {
	Fixed tArea;
	tArea = (
			( A.getX() * (B.getY() - C.getY())) +
			( B.getX() * (C.getY() - A.getY())) +
			( C.getX() * (A.getY() - B.getY()))
			) / 2;
	return (tArea);
}

/// @brief 		Here's a C++ function that checks if a point is inside a
///				triangle using the area method or barycentric coordinates:
/// @param P 	Point P x,y coordinates in Fixed type
/// @param A 	Triangle vertice Point A x,y coordinates in Fixed type
/// @param B 	Triangle vertice Point A x,y coordinates in Fixed type
/// @param C 	Triangle vertice Point A x,y coordinates in Fixed type
/// @return 	TRUE if P is iside traiangle FASLE otherwise
bool bsp(Point &P, Point &A, Point &B, Point &C) {
	// #1 Calculate the area of the entire triangle ABC
	Fixed triangleArea = areaOfTriangle(A,B,C);

	// #2 minimal value > 0 of the fixed type coordinates
	float epsilon = (1 / (256.0f));

	// #3 Check if area of triangle is ZERO (NOT a triangle)
	if (std::abs(triangleArea.toFloat()) <= epsilon) {
		std::cout << "ERROR : Triangle NOT VALID! Area = " << std::abs(triangleArea.toFloat() / 2) << std::endl;
		return 0;
	}

	// #4 Calculate de area of each sub-triangle formed by connecting the
	// point P with each pair or vertices, AB BC CA
	float uArea = std::abs((areaOfTriangle(P,B,C) / triangleArea).toFloat());
	float vArea = std::abs((areaOfTriangle(P,C,A) / triangleArea).toFloat());
	float wArea = std::abs((areaOfTriangle(P,A,B) / triangleArea).toFloat());

	// #5 if any of u, v, w areas are zero then point is on edges or vertices
	if (!(uArea > epsilon) || !(vArea > epsilon) || !(wArea > epsilon)) {
		if (!(uArea > epsilon) && !(vArea > epsilon) && (wArea > epsilon))
			std::cout << "P is on VERTEX C " << std::endl;
		else if (!(uArea > epsilon) && (vArea > epsilon) && !(wArea > epsilon))
			std::cout << "P is on VERTEX B" << std::endl;
		else if ((uArea > epsilon) && !(vArea > epsilon) && !(wArea > epsilon))
			std::cout << "P is on VERTEX A" << std::endl;
		else if (!(uArea > epsilon) && (vArea > epsilon) && (wArea > epsilon))
			std::cout << "P is on EDGE *BC " << std::endl;
		else if ((uArea > epsilon) && (vArea > epsilon) && !(wArea > epsilon))
			std::cout << "P is on EDGE *AB" << std::endl;
		else if ((uArea > epsilon) && !(vArea > epsilon) && (wArea > epsilon))
			std::cout << "P is on EDGE *CA" << std::endl;
		return 0;
	}

	// #6 Else triangle ABC exists and P point is inside triangle (sum = 1)
	// or outside the triangle sum > 1
	float tolerance = 1/64.0;
	return (std::abs(uArea + vArea + wArea - 1) < tolerance);
}
