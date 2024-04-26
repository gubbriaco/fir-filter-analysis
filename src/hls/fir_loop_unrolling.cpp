#include "definitions.h"


/**
 * Loop Unrolling Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrolling(samplesType inputFilter, samplesType* outputFilter) {

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
	 *
	 */
	loopShifting: for( i=SIZE-1; i>1; i=i-2 ) {
		shiftRegister[i] = shiftRegister[i-1];
		shiftRegister[i-1] = shiftRegister[i-2];
	}
	shiftRegister[1] = shiftRegister[0];
	shiftRegister[0] = inputFilter;

	loopAccumulator: for( i=SIZE-1; i>1; i=i-2 ) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
		accumulator += shiftRegister[i-1] * coefficientsFilter[i-1];
	}
	accumulator += shiftRegister[1] * coefficientsFilter[1];
	accumulator += inputFilter * coefficientsFilter[0];

	*outputFilter = accumulator;

}
