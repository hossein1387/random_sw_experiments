#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <bitset>
#define SIZE_OF_ARRAY   100000
#define NUM_BITS        31
#define MAX_RAND_VAL    (1<<NUM_BITS)


int popcount(int v) {
	int c;
    v = v - ((v >> 1) & 0x55555555);                // put count of each 2 bits into those 2 bits
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333); // put count of each 4 bits into those 4 bits  
    return c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}

int min_Hamming(unsigned int tab[], unsigned int tab_size) {

	unsigned int min_hamming_dist = 0xFFFFFFFF;

	for(int i=0; i<tab_size-2; i++)
	{
		for(int j=i+1; j<tab_size; j++){
			unsigned int hamming_dist = popcount(tab[i] ^ tab[j]);			
            /*printf("hamming dist %s(%4d) and %s(%4d) = %0d\n", std::bitset<32>(tab[i]).to_string().c_str(), 
            	   tab[i], std::bitset<32>(tab[j]).to_string().c_str(), tab[j], popcount(hamming_dist));*/
			if(hamming_dist==0) // if there is a hamming distance of zero, noone can beat it, return! 
				return 0;
			if(hamming_dist<min_hamming_dist)
				min_hamming_dist = hamming_dist;
		}
	}

	return min_hamming_dist;
}

int main()
{
	  /* initialize random seed: */
  srand (time(NULL));
  unsigned int test_array[SIZE_OF_ARRAY];

  /* generate secret number between 0 and SIZE_OF_ARRAY: */
  for(int i=0; i<SIZE_OF_ARRAY; i++){
      test_array[i]  = rand() % MAX_RAND_VAL;  	
  }
  
  printf("min hamming distance is=%0d\n", min_Hamming(test_array, SIZE_OF_ARRAY));
  
  return 0;
}


