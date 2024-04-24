#include "definitions.h"


/**
 * For a causal discrete-time FIR filter, each value of the output sequence is a weighted sum of the most recent input values.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolution(samplesType inputFilter, samplesType* outputFilter) {

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
	 * This loop implements the convolution operation between the vector of input samples stored
	 * in the shiftRegister scroll register and the vector of FIR filter coefficientsFilter
	 * coefficients. The result of this convolution is accumulated in the accumulator variable,
	 * which represents the FIR filter output for the current input sample inputFilter.
	 */
	loop: for( i=SIZE-1; i>=0; --i ) {
		if( i==0 ) {
			accumulator += inputFilter * coefficientsFilter[0];
			shiftRegister[0] = inputFilter;
		} else {
			shiftRegister[i] = shiftRegister[i-1];
			accumulator += shiftRegister[i] * coefficientsFilter[i];
		}
	}

	*outputFilter = accumulator;

}
