#include "definitions.h"


/**
 * Code Hoisting Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionCodeHoisting(samplesType inputFilter, samplesType* outputFilter) {

	/**
	 * Data structure containing the coefficients of the FIR filter.
	 */
	coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	/**
	 * The following data structure is declared static so that it is initialized only once.
	 * Specifically, used in the for loop that will be declared later, the static declaration
	 * allows initialization only on the first iteration of that loop.
	 */
	static samplesType shiftRegister[SIZE];

	/**
	 * Accumulator for intermediate results.
	 */
	accType accumulator;
	accumulator = 0;

	int i;
	/**
	 * This loop provides one less iteration than normal so as to implement the if part of
	 * the code for the base case (i==0) outside the for loop and thus avoiding a resource-
	 * level overhead to implement that just-mentioned if.
	 */
	loop: for( i=SIZE-1; i>0; --i ) {
		shiftRegister[i] = shiftRegister[i-1];
		accumulator += shiftRegister[i] * coefficientsFilter[i];
	}
	accumulator += inputFilter * coefficientsFilter[0];
	shiftRegister[0] = inputFilter;

	*outputFilter = accumulator;

}
