/**
 * @file p008.cpp
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   May 22, 2015
 */


#include <string.h>
#include <iostream>

const int adjacent_digits = 3;

const char* input = "73167176531330624919225119674426574742355349194934"
					"96983520312774506326239578318016984801869478851843"
					"85861560789112949495459501737958331952853208805511"
					"12540698747158523863050715693290963295227443043557"
					"66896648950445244523161731856403098711121722383113"
					"62229893423380308135336276614282806444486645238749"
					"30358907296290491560440772390713810515859307960866"
					"70172427121883998797908792274921901699720888093776"
					"65727333001053367881220235421809751254540594752243"
					"52584907711670556013604839586446706324415722155397"
					"53697817977846174064955149290862569321978468622482"
					"83972241375657056057490261407972968652414535100474"
					"82166370484403199890008895243450658541227588666881"
					"16427171479924442928230863465674813919123162824586"
					"17866458359124566529476545682848912883142607690042"
					"24219022671055626321111109370544217506941658960408"
					"07198403850962455444362981230987879927244284909188"
					"84580156166097919133875499200524063689912560717606"
					"05886116467109405077541002256983155200055935729725"
					"71636269561882670428252483600823257530420752963450";

int main(){

	unsigned char numbers[adjacent_digits]; // array of 13 numbers
	unsigned long result = 1;               // result of the calculation;

	unsigned char scratch_numbers[adjacent_digits]; // used to temporarily record
	unsigned long scratch_result = 1;               //
	int current_index = 0;
	int current_count = 0;

	char* ptr = (char*) input;

	// Loop through all characters
	while(*ptr){

		unsigned char digit = *ptr - '0'; // Calculate the numeric value

		// Anything multiplied by 0 is 0, so If '0' is encountered,
		// reset all adjacent digits to after the position it was discovered
		if(digit == 0){
			ptr++;      // skip zero
			current_index  = 0;
			current_count  = 0;
			scratch_result = 1;
			continue;
		}
		// If we have calculated the sum of the n digits, remove the first adjacent one from the product
		if( current_count == adjacent_digits ){
			scratch_result /= scratch_numbers[current_index % adjacent_digits]; // Remove the last digit
			current_count--;
		}

		scratch_numbers[current_index % adjacent_digits] = digit; // Add to scratch
		scratch_result *= digit;                                  // Multiply for result
		current_index++;
		ptr++;
		current_count++;
		if(current_count == adjacent_digits){
			if( scratch_result > result ){
				int offset = current_index % adjacent_digits;
				// Record the result and the digits found
				result = scratch_result;
				// Correct the order numbers were discovered using modular arithmetic
				memcpy(numbers, scratch_numbers + offset, adjacent_digits - offset);
				memcpy(numbers + adjacent_digits - offset, scratch_numbers, offset);
			}
		}
	}

	// Print the end result
	for( int i=0; i < adjacent_digits; ++i ){
		std::cout << (int) numbers[i];
	}
	std::cout << '\n';
	for( int i=0; i < adjacent_digits; ++i ){
		std::cout << (int) numbers[i];
		if( i + 1 < adjacent_digits ){
			std::cout << " * ";
		}
	}
	std::cout << " = " << result;


	return 0;
}

