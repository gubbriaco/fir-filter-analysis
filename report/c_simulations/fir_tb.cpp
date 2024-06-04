#include "definitions.h"
#include <stdio.h>
#include "ap_int.h"
#include <iostream>


void firConvolutionUnoptimized(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionOperationChaining(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopFission(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionCodeHoisting(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor2(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor2Pragma(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor2PP(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor4(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor4Pragma(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopUnrollingFactor4PP(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopPipelining(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionBitwidthOptimization(ap_int<8> inputFilter, ap_int<18+SIZE>* outputFilter);
void firConvolutionAXI(hls::stream<AXI_TYPE> &inputStreamFilter, hls::stream<AXI_TYPE> &outputStreamFilter);


int main() {

    samplesType inputFilter[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    samplesType outputFilter;

    printf("\n*******firConvolutionUnoptimized*******\n");
    printf("%-20s%-20s%-20s\n", "iteration", "inputFilter[i]", "outputFilter[i]");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionUnoptimized( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionOperationChaining*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionOperationChaining( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionCodeHoisting*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionCodeHoisting( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopFission*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopFission( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor2*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor2( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor2Pragma*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor2Pragma( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor2PragmaPartitioning*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor2PP( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor4*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor4( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor4Pragma*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor4Pragma( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopUnrollingFactor4PragmaPartitioning*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopUnrollingFactor4PP( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    printf("\n*******firConvolutionLoopPipelining*******\n");
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionLoopPipelining( inputFilter[i], &outputFilter );
        printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
    }

    ap_int<8> inputFilterAp[SIZE] = {42, 7, 58, 120, -64, 15, -89, -75, 43, 43, -14};
    ap_int<18+SIZE> outputFilterAp;
    std::cout << "\n*******firConvolutionBitwidthOptimization*******\n";
    for( int i=0; i<SIZE; ++i ) {
        firConvolutionBitwidthOptimization( inputFilterAp[i], &outputFilterAp );
        std::cout << std::left << std::setw(20) << i
                  << std::left << std::setw(20) << inputFilterAp[i]
                  << std::left << std::setw(20) << outputFilterAp << "\n";
    }

    hls::stream<AXI_TYPE> inputStreamFilter;
    hls::stream<AXI_TYPE> outputStreamFilter;
    AXI_TYPE inFilter, outFilter;
    for (int i=0; i<SIZE; i++) {
        inFilter.data=inputFilter[i];
        inFilter.strb = -1;
        inFilter.keep = 15;
        inFilter.user = 0;
        inFilter.last = (i==SIZE-1) ? 1 : 0;
        inFilter.id = 0;
        inFilter.dest = 0;
        inputStreamFilter << inFilter;
    }
    printf("\n*******firConvolutionAXI*******\n");
    firConvolutionAXI( inputStreamFilter, outputStreamFilter );
    for( int i=0; i<SIZE; ++i ) {
        outFilter = outputStreamFilter.read();
        printf("%-20d%-20d%-20d\n", i, inFilter.data.to_int(), outFilter.data.to_int());
    }

    return 0;

}
