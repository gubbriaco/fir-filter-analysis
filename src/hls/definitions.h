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
 * Loop Fission Design.
 * @param inputFilter
 * @param outputFilter
 */
void firConvolutionLoopFission(samplesType inputFilter, samplesType* outputFilter);


#endif
