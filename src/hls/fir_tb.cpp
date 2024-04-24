#include "definitions.h"
#include <stdio.h>


void firConvolution(samplesType inputFilter, samplesType* outputFilter);


int main() {

	samplesType inputFilter[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	samplesType outputFilter;

	printf("%-20s%-20s%-20s\n", "iteration", "inputFilter[i]", "outputFilter[i]");
	for( int i=0; i<SIZE; ++i ) {
		firConvolution( inputFilter[i], &outputFilter );
		printf("%-20d%-20d%-20d\n", i, inputFilter[i], outputFilter);
	}

	return 0;

}
