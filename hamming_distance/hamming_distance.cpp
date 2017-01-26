#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <bitset>
#include <fstream>
#define SIZE_OF_ARRAY    10
#define NUM_BITS         31
#define MAX_RAND_VAL     (1<<NUM_BITS)
#define OUTPUT_FILE_NAME "array.txt"

unsigned int hamming_res[SIZE_OF_ARRAY];

int popcount(int v) {
	int c;
    v = v - ((v >> 1) & 0x55555555);                // put count of each 2 bits into those 2 bits
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333); // put count of each 4 bits into those 4 bits  
    return c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}

int min_Hamming(unsigned int tab[], unsigned int tab_size) {

	unsigned int min_hamming_dist = 33;
#if DEBUG==1
	unsigned int cnt = 0;
#endif            
	for(int i=0; i<tab_size-1; i++)
	{
		for(int j=i+1; j<tab_size; j++){
			unsigned int hamming_dist = popcount(tab[i] ^ tab[j]);			
#if DEBUG==1
            hamming_res[cnt] = hamming_dist;
            printf("[%3d] hamming dist %s(%10d) and %s(%10d) = %2d\n",cnt, std::bitset<32>(tab[i]).to_string().c_str(), 
            	   tab[i], std::bitset<32>(tab[j]).to_string().c_str(), tab[j], hamming_dist);
            cnt++;
#endif            
			if(hamming_dist==0) // if there is a hamming distance of zero, noone can beat it, return! 
				return 0;
			if(hamming_dist < min_hamming_dist)
				min_hamming_dist = hamming_dist;
		}
	}
	return min_hamming_dist;
}


int main()
{
  
  // prepare output file
#if DEBUG==1
  std::ofstream array_file;
  array_file.open (OUTPUT_FILE_NAME);
#endif 
  // initialize random seed and test array
  srand (time(NULL));
  unsigned int test_array[SIZE_OF_ARRAY];
  int min_hdist;

  // generate random numbers between 0 and SIZE_OF_ARRAY 
  for(int i=0; i<SIZE_OF_ARRAY; i++){
      test_array[i]  = rand() % MAX_RAND_VAL;  	
  }

  // call min hamming function to compute min hamming of the array
  min_hdist = min_Hamming(test_array, SIZE_OF_ARRAY);

#if DEBUG==1
  int cnt = 0;
  for(int i=0; i<SIZE_OF_ARRAY-1; i++){
  	for(int j=i+1; j<SIZE_OF_ARRAY; j++){
    	array_file << test_array[i] << "," << test_array[j] << "," << hamming_res[cnt] << std::endl;
  		cnt++;
	}
  }
  array_file << "min_hamming_dist" << "," << min_hdist << std::endl;
  array_file.close();
#endif  
  return 0;
}

