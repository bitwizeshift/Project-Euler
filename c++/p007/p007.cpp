/**
 * @file p007.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 23, 2015
 */


#include <cmath>
#include <iostream>

typedef unsigned long value_type;

static const value_type prime_to_find = 10001;

bool is_prime( value_type p ){
	if( (p != 2) && ((p % 2) == 0) ) return false;

	for(value_type i=3; i < sqrt(p); i += 2) {
		if (p % i == 0) {
			return false;
		}
	}

	return true;
}


int main(){
	// Count 2 as the first prime
	int count = 1;
	int p = 3;
	for(;count < prime_to_find;p+=2){
		if( is_prime(p) ){
			++count;
		}
	}

	// Output the prime
	std::cout << "The " << prime_to_find << " prime is " << p << "\n";
}
