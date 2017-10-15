/**
 * @file p005.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 23, 2015
 */


#include <iostream>

typedef unsigned int value_type;

value_type gcd( value_type m, value_type n ){
	while(m!=n){
		if(m>n) m=m-n;
		else n = n-m;
	}
	return m;
}

value_type lcm( value_type a, value_type b ){
	return (a/gcd(a, b))*b;
}

const value_type value_start     = 2520;
const value_type div_range_start = 1;
const value_type div_range_end   = 20;

int main(){

	value_type x=1;
	for( value_type i=1; i<20; ++i ){
		x=lcm(x, i+1);
	}

	std::cout << x << "\n";

	return 0;
}

