#include "definitions.h"

void firConvolutionLoopUnrollingFactor4(samplesType inputFilter, samplesType* outputFilter) {
	coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
	static samplesType shiftRegister[SIZE];
	accType accumulator;
	accumulator = 0;
	int i;
	loopShifting: for( i=SIZE-1; i>1; i=i-4 ) {
		shiftRegister[i] = shiftRegister[i-1];
		shiftRegister[i-1] = shiftRegister[i-2];
		shiftRegister[i-2] = shiftRegister[i-3];
		shiftRegister[i-3] = shiftRegister[i-4];
	}
	if( i==1 ) {
		shiftRegister[1] = shiftRegister[0];
	}
	shiftRegister[0] = inputFilter;
	loopAccumulator: for( i=SIZE-1; i>=3; i=i-4 ) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
		accumulator += shiftRegister[i-1] * coefficientsFilter[i-1];
		accumulator += shiftRegister[i-2] * coefficientsFilter[i-2];
		accumulator += shiftRegister[i-3] * coefficientsFilter[i-3];
	}
	for(; i>=0; --i) {
		accumulator += shiftRegister[i] * coefficientsFilter[i];
	}
	*outputFilter = accumulator;
}