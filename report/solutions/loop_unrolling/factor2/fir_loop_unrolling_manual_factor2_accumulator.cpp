#include "definitions.h"

void firConvolutionLoopUnrollingFactor2(samplesType inputFilter, samplesType* outputFilter) {
	coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
	static samplesType shiftRegister[SIZE];
	accType accumulator;
	accumulator = 0;
	int i;
	loopShifting: for( i=SIZE-1; i>1; i=i-2 ) {
		shiftRegister[i] = shiftRegister[i-1];
		shiftRegister[i-1] = shiftRegister[i-2];
	}
	if( i==1 ) {
		shiftRegister[1] = shiftRegister[0];
	}
	shiftRegister[0] = inputFilter;
	loopAccumulator: for( i=SIZE-1; i>=1; i=i-2 ) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
		accumulator += shiftRegister[i-1] * coefficientsFilter[i-1];
	}
	for(; i>=0; --i) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
	}
	*outputFilter = accumulator;
}