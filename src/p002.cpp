/**
 * @file p002.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 22, 2015
 */

const int limit = 4000000;

#include <iostream>

int main(){

	int a = 1;
	int b = 1;
	int sum = 0;
	while(a + b < limit){
		int temp = b;
		b = a + b;
		a = temp;
		if( b % 2 == 0){
			sum += b;
		}
	};
	std::cout << sum;

	return 0;
}


