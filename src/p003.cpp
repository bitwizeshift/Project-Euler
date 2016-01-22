/**
 * @file p003.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 22, 2015
 */


#include <iostream>

typedef unsigned long long value_type;

const value_type prime_factor = 600851475143UL;

///
/// Uses bottom-up approach to finding greatest prime factor
///
value_type greatest_prime_factor( value_type n ){

	int max_factor = 1; // record the greatest factor
	int d = 2;          // Initial divisor
	while(n > 1){
		while( n % d == 0 ){
			if( max_factor < d ){
				max_factor = d;  // Record the greatest factor (if it's the greatest)
			}
			n /= d; // Divide by the factor
		}
		d += 1; // Increase divisor d
	}
	return max_factor;
}

int main(){

	std::cout << greatest_prime_factor(prime_factor);

	return 0;
}
