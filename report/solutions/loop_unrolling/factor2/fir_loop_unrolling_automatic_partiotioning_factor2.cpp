#include "definitions.h"

void firConvolutionLoopUnrollingFactor2PP(samplesType inputFilter, samplesType* outputFilter) {
    coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static samplesType shiftRegister[SIZE];
    accType accumulator;
    accumulator = 0;
    int i;
    loopShifting: for( i=SIZE-1; i>0; --i ) {
        #pragma HLS array_partition variable=shiftRegister complete
        #pragma HLS unroll factor=2
        shiftRegister[i] = shiftRegister[i-1];
    }
    shiftRegister[0] = inputFilter;
    accumulator = 0;
    loopAccumulator: for( i=SIZE-1; i>=0; --i ) {
        accumulator += shiftRegister[i] * coefficientsFilter[i];
    }
    *outputFilter = accumulator;
}