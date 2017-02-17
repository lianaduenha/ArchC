
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_FAILURE_MODE

unsigned int stuckAt (unsigned int data, int bit, int value, float refProb)
{
	float n = ((float) (rand()%101)) / 100;

    #ifdef DEBUG_FAILURE_MODE
    printf("\nn=%f, refProb=%f, data=%u -> ", n, refProb, (unsigned int) data );
    #endif

	if (n < refProb)
    	data = value==0? data & ((1<<bit)^0xFFFFFFFF) : data | (1<<bit);

    #ifdef DEBUG_FAILURE_MODE
	printf("%u", (unsigned int) data);
	#endif

	return data;
	
}

unsigned int stuckHigh (unsigned int data, int bit, float refProb)
{
	return stuckAt (data, bit, 1, refProb);
}

unsigned int stuckLow (unsigned int data, int bit, float refProb)
{
	return stuckAt (data, bit, 0, refProb);
}

unsigned int bitFlip (unsigned int data, int bit, float refProb)
{
	float n = ((float) (rand()%101)) / 100;
	#ifdef DEBUG_FAILURE_MODE
	printf("\nn=%f, refProb=%f, data=%u -> ", n, refProb, (unsigned int) data);
	#endif
	
	if (n < refProb) data = data ^ (1 << bit);
	
	#ifdef DEBUG_FAILURE_MODE
	printf("%u", (unsigned int) data);
	#endif

	return data;
}

unsigned int randomBitFlip (unsigned int data, float refProb)
{
	int bit = rand()%32;

	return bitFlip (data, bit, refProb);
}

