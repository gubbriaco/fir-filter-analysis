#include "definitions.h"

void firConvolutionAXI(hls::stream<AXI_TYPE> &inputStreamFilter, hls::stream<AXI_TYPE> &outputStreamFilter) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE axis port=inputStreamFilter
	#pragma HLS INTERFACE axis port=outputStreamFilter
	AXI_TYPE inFilter, outFilter;
	coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
	static samplesType shiftRegister[SIZE];
	while( inputStreamFilter.read_nb(inFilter) ) {
		#pragma HLS pipeline II=1
		accType accumulator;
		accumulator = 0;
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