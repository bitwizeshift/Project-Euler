/**
 * @file p1-templated.cpp
 *
 * @todo Add description
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   Jan 22, 2016
 */

#include <iostream>

#if defined(_MSC_VER) || defined(__INTEL)
#	define FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#	define FORCE_INLINE inline __attribute__((always_inline))
#else
#	define FORCE_INLINE inline
#endif

/**
 * Only adds the value of i if it is divisbly by 5 or 7.
 * This is implicitly castable to int
 */
template<
	int i,
	bool added = ((i % 5)==0) || ((i % 7)==0)
>
struct EulerProblem{
	FORCE_INLINE operator int(){ return 0; }
};

template<int i>
struct EulerProblem<i,true>{
	FORCE_INLINE operator int(){ return i; }
};

//----------------------------------------------------------------------------

/**
 * Iterates through template expansion until @p end is reached, adding
 * the value from the EulerProblem -- if it is applicable.
 *
 * The FORCE_INLINE statements will tell the compiler (assuming gcc, msvc, intel,
 * or clang) to write this all into 1 expression, and a high optimizing pass
 * (e.g. -O3) should result in a compile-time constant integer.
 *
 * Most compilers will need to up the recursion depth for this to be available
 */
template<int current, int end>
struct ForEachEuler{
	FORCE_INLINE static int calculate(){
		return ForEachEuler<current+1,end>::calculate() + EulerProblem<current>();
	}
};

template<int current>
struct ForEachEuler<current,current>{
	FORCE_INLINE static int calculate(){
			return 0;
		}
};

int main(){

	std::cout << ForEachEuler<1,1000>::calculate();

	return 0;
}


