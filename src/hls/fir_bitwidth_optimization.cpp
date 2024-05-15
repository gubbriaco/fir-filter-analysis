#include "definitions.h"
#include "ap_int.h"


/**
 * Bitwidth Optimization Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionBitwidthOptimization(ap_int<32> inputFilter, ap_int<64+(SIZE-1)>* outputFilter) {

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
	//const int precision = 64; // pari a quella della prima moltiplicazione che richiede sempre 64 bit
	//ap_int<64+(SIZE-1)> accumulator; // pari alla precisione finale dell'output
	accType accumulator;
	accumulator = 0;

	/**
	 * A bitwidth equal to 4 is set since, the SIZE variable being equal to 11, the number of bits,
	 * in order for the representation to represent the index i which will be between 0 and 10
	 * (inclusive) to be reliable, is equal to 4.
	 */
	int i;
	/**
	 * This loop implements the convolution operation between the vector of input samples stored
	 * in the shiftRegister scroll register and the vector of FIR filter coefficientsFilter
	 * coefficients. The result of this convolution is accumulated in the accumulator variable,
	 * which represents the FIR filter output for the current input sample inputFilter.
	 */
	loop: for( i=SIZE-1; i>0; --i ) {
			shiftRegister[i] = shiftRegister[i-1];
			accumulator += shiftRegister[i] * coefficientsFilter[i];
		}
		accumulator += inputFilter * coefficientsFilter[0];
		shiftRegister[0] = inputFilter;

	*outputFilter = accumulator;

}
