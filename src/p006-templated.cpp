/*
 * main.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Bitwize
 */


#include <iostream>

typedef unsigned int value_type;

template<typename T, T v>
struct integral_constant{
	static const T            value = v; ///< Value of integral constant
	typedef T                 value_type;  ///< The type of this class
	typedef integral_constant type;        ///< The type of this integral_constant
};

/// Calculate the sum of the values between a and b
template<unsigned int a, unsigned int b>
struct sum_of_range : public integral_constant<unsigned int, ((b)*(b+1) - (a)*(a+1))/2>{};

/// Calculate the square sum of the values between a and b
template<unsigned int a, unsigned int b>
struct square_sum_of_range : public integral_constant<unsigned int, 1 + ((b*b*b)/3 + b*b/2 + b/6) - ((a*a*a)/3 + a*a/2 + a/6) >{};

int main(){

	// 25164150
	std::cout << integral_constant< int, sum_of_range<0,100>::value * sum_of_range<0,100>::value - square_sum_of_range<0,100>::value >::value << '\n';

	return 0;
}
