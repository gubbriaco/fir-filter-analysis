#include "definitions.h"


/**
 * Loop Unrolling Factor=2 with Unrolling Pragma and Partitioning Pragma Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor2PragmaPartitioning(samplesType inputFilter, samplesType* outputFilter) {

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
	loop: for( i=SIZE-1; i>=0; --i ) {
		#pragma HLS array_partition variable=shiftRegister complete
		#pragma HLS unroll factor=2
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
