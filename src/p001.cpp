/**
 * @file p001.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 22, 2015
 *
 */

#include <iostream>

int main(){

	int count = 0;
	for(int i=1; i<1000; ++i){
		if( i%3==0 || i%5==0 ){
			count += i;
		}
	}
	std::cout << count;

	return 0;
}
