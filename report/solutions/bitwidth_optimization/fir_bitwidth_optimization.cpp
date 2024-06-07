#include "definitions.h"
#include "ap_int.h"

void firConvolutionBitwidthOptimization(ap_int<8> inputFilter, ap_int<18+SIZE>* outputFilter) {
	ap_int<10> coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
	static ap_int<8> shiftRegister[SIZE];
	ap_int<18+SIZE> accumulator;
	accumulator = 0;
	ap_int<5> i;
	loop: for( i=SIZE-1; i>0; --i ) {
		shiftRegister[i] = shiftRegister[i-1];
		accumulator += shiftRegister[i] * coefficientsFilter[i];
	}
	accumulator += inputFilter * coefficientsFilter[0];
	shiftRegister[0] = inputFilter;
	*outputFilter = accumulator;
}