#include "ap_int.h"
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <stdio.h>



#ifndef DEFINITIONS_H


/**
 * Represents FIR filter size
 * @param SIZE FIR filter size
 */
#define SIZE 11

/**
 * Represents the data type used to store the coefficients of the FIR filter
 * @param coeffsType data type for FIR filter coefficients
 */
typedef int coeffsType;

/**
 * Represents the data type used to store the filter input samples
 * @param samplesType data type for FIR filter input samples
 */
typedef int samplesType;

/**
 * Represents the data type used to store the intermediate accumulator when calculating the filter output.
 * @param accType data type for FIR filter intermediate accumulator
 */
typedef int accType;

/**
 * Unoptimized Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionUnoptimized(samplesType inputFilter, samplesType* outputFilter);

/**
 * Operation Chaining Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionOperationChaining(samplesType inputFilter, samplesType* outputFilter);

/**
 * Code Hoisting Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionCodeHoisting(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Fission Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopFission(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=2 Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor2(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=2 with Unrolling Pragma Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor2Pragma(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=2 with Unrolling Pragma and Partitioning Pragma Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor2PragmaPartitioning(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=4 Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor4(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=4 with Unrolling Pragma Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor4Pragma(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Unrolling Factor=4 with Unrolling Pragma and Partitioning Pragma Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopUnrollingFactor4PragmaPartitioning(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Pipelining Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopPipelining(samplesType inputFilter, samplesType* outputFilter);

/**
 * Loop Pipelining Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionBitwidthOptimization(ap_int<32> inputFilter, ap_int<64+(SIZE-1)>* outputFilter);

/**
 * Represents the AXI type for AXI-stream interface.
 * @param AXI_TYPE AXI type
 */
typedef ap_axiu<32, 2, 5, 6> AXI_TYPE;

/**
 * AXI Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionAXI(hls::stream<AXI_TYPE> &inputStreamFilter, hls::stream<AXI_TYPE> &outputStreamFilter);


#endif
