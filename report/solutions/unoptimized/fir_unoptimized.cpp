#include "definitions.h"

void firConvolutionUnoptimized(samplesType inputFilter, samplesType* outputFilter) {
    coeffsType coefficientsFilter[SIZE] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
    static samplesType shiftRegister[SIZE];
    accType accumulator;
    accumulator = 0;
    int i;
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
