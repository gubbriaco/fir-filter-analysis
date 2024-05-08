#include "definitions.h"


/**
 * AXI Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionAXI(hls::stream<AXI_TYPE> &inputStreamFilter, hls::stream<AXI_TYPE> &outputStreamFilter) {

	/**
	 * The input inputStreamFilter and output outputStreamFilter must be mapped to the AXI Stream standard.
	 */
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE axis port=inputStreamFilter
	#pragma HLS INTERFACE axis port=outputStreamFilter

	/**
	 * Two temporary variables are defined for processing.
	 */
	AXI_TYPE inFilter, outFilter;

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
	 * A while loop is defined taking into account that the stream read must be "non-blocking", that is, assuming that the initial data sizes are not known a priori.
	 */
	while( inputStreamFilter.read_nb(inFilter) ) {
		/* The tool is asked to synthesize a design so that an II (Iteration Interval)
		 * of 1 is guaranteed, i.e., such that a unit throughput that results in the best pipelining
		 * solution.
		 */
		#pragma HLS pipeline II=1
		/**
		 * Accumulator for intermediate results.
	     */
		accType accumulator;
		accumulator = 0;
		/**
		 * This loop implements the convolution operation between the vector of input samples stored
		 * in the shiftRegister scroll register and the vector of FIR filter coefficientsFilter
		 * coefficients. The result of this convolution is accumulated in the accumulator variable,
		 * which represents the FIR filter output for the current input sample inputFilter.
		 */
		loop: for( int i=SIZE-1; i>=0; i-- ) {
			if( i==0 ) {
				accumulator += inFilter.data*coefficientsFilter[0];
				shiftRegister[0] = inFilter.data;
			} else {
				shiftRegister[i] = shiftRegister[i-1];
				accumulator += shiftRegister[i] * coefficientsFilter[i];
			}
		}
		outFilter.data=(accumulator);
		outFilter.strb = 15;
		outFilter.keep = 15;
		outFilter.user = 1;
		outFilter.last = inFilter.last;
		outFilter.id = 0;
		outFilter.dest = 0;
		outputStreamFilter.write(outFilter);
	}

}
