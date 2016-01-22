/**
 * @file p006.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 23, 2015
 */



#include <iostream>

typedef unsigned int value_type;

value_type square_of_sum( value_type n ){
	return (n*n*(n+1)*(n+1))/4;
}

value_type sum_of_square( value_type n ){
	return ((n*n*n)/3 + n*n/2 + n/6) + 1;
}

int main(){

	// 25164150
	std::cout << square_of_sum(100) - sum_of_square(100) << '\n';

	return 0;
}
