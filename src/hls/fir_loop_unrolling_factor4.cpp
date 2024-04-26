#include "definitions.h"


/**
 * Loop Unrolling Factor=4 Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor4(samplesType inputFilter, samplesType* outputFilter) {

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
	loopShifting: for( i=SIZE-1; i>3; i=i-4 ) {
		shiftRegister[i] = shiftRegister[i-1];
		shiftRegister[i-1] = shiftRegister[i-2];
		shiftRegister[i-2] = shiftRegister[i-3];
		shiftRegister[i-3] = shiftRegister[i-4];
	}
	shiftRegister[3] = shiftRegister[2];
	shiftRegister[2] = shiftRegister[1];
	shiftRegister[1] = shiftRegister[0];
	shiftRegister[0] = inputFilter;

	loopAccumulator: for( i=SIZE-1; i>3; i=i-4 ) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
		accumulator += shiftRegister[i-1] * coefficientsFilter[i-1];
		accumulator += shiftRegister[i-2] * coefficientsFilter[i-2];
		accumulator += shiftRegister[i-3] * coefficientsFilter[i-3];
	}
	accumulator += shiftRegister[3] * coefficientsFilter[3];
	accumulator += shiftRegister[2] * coefficientsFilter[2];
	accumulator += shiftRegister[1] * coefficientsFilter[1];
	accumulator += inputFilter * coefficientsFilter[0];

	*outputFilter = accumulator;

}
