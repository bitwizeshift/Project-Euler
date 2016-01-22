/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Bitwize
 */

#include <cmath>
#include <iostream>

typedef unsigned int value_type;

/// Isolates the nth digit, counted from the right. Digits are 0-indexed
value_type isolate_digit( value_type v, int digit ){
	return ((v / (value_type) pow(10,digit) ) % (value_type) 10u);
}

/// Check if a value is a palindrome
bool is_palindrome( value_type v ){
	if(v<=9) return true;  // Trivially true

	int digits = std::log10(v);

	int high = digits;
	int low  = 0;

	bool is_valid = true;
	while( is_valid && (high-low>0) ){
		if( isolate_digit(v, low) != isolate_digit(v, high) ){
			is_valid = false;
		}else{
			--high;
			++low;
		}

	}
	return is_valid;
}


int main(){

	value_type a = 999;
	value_type b = 999;

	bool is_found = false;
	while(!is_found){
		while(!is_found && a > 100){
			is_found = is_palindrome( a * b );
			if(!is_found){
				--a;
			}
		}
		if(!is_found){
			a = b;
			--b;
		}

	}
	std::cout << a << " x " << b << " = " << a*b;

	return 0;
}
