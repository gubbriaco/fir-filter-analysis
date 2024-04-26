#include "definitions.h"
#include <stdio.h>


void firConvolutionUnoptimized(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionOperationChaining(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionLoopFission(samplesType inputFilter, samplesType* outputFilter);
void firConvolutionCodeHoisting(samplesType inputFilter, samplesType* outputFilter);


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

	return 0;

}
