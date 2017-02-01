
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;
#define NUM_BATCH        3
#define SIZE_OF_ARRAY    4
#define NUM_BITS         31
#define MAX_RAND_VAL     (1<<NUM_BITS)
#define OUTPUT_FILE_NAME "array.txt"

struct batchinf_t{
  int   threadid;
  int   sizeToProcess;
  unsigned int*  arrayptr;
};


unsigned int hamming_res[SIZE_OF_ARRAY];
int min_Hamming(unsigned int tab[], unsigned int tab_size, int threadid);

int popcount(int v) {
	int c;
    v = v - ((v >> 1) & 0x55555555);                // put count of each 2 bits into those 2 bits
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333); // put count of each 4 bits into those 4 bits  
    return c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}


void printarray(unsigned int* array, int sz, int threadid)
{
  printf("[id=%0d] ", threadid );
  for(int i=0; i<sz; i++)
    printf("%0d, ", array[i] );
}


void *thread(void *threadargs) {
   struct batchinf_t *batch_inf;
   int hamming_dist = 0;
   batch_inf = (struct batchinf_t *) threadargs;
   hamming_dist = min_Hamming(batch_inf->arrayptr, batch_inf->sizeToProcess, batch_inf->threadid);
   printf("[thred.id=%0d]: min_hamming_dist=%0d\n", batch_inf->threadid, hamming_dist) ;
   hamming_res[batch_inf->threadid] = hamming_dist;
   pthread_exit(NULL);
}



int min_Hamming(unsigned int tab[], unsigned int tab_size, int threadid) {

unsigned int min_hamming_dist = 33;
	unsigned int cnt = 0;
	for(int i=0; i<tab_size-1; i++)
	{
			unsigned int hamming_dist = popcount(tab[i] ^ tab[i+1]);			
            printf("[thred.id=%0d] [%3d] hamming dist %s(%10d) and %s(%10d) = %2d\n",threadid, cnt, std::bitset<32>(tab[i]).to_string().c_str(), 
            	   tab[i], std::bitset<32>(tab[i+1]).to_string().c_str(), tab[i+1], hamming_dist);
            cnt++;
			if(hamming_dist==0) // if there is a hamming distance of zero, noone can beat it, return! 
				return 0;
			if(hamming_dist < min_hamming_dist)
				min_hamming_dist = hamming_dist;
		}
	return min_hamming_dist;
}


int main()
{
  
  // prepare output file
  std::ofstream array_file;
  array_file.open (OUTPUT_FILE_NAME);
  // initialize random seed and test array
  srand (time(NULL));
  unsigned int test_array[SIZE_OF_ARRAY];
  int min_hdist=33;
  pthread_t threads[NUM_BATCH];
  struct batchinf_t batchinf[NUM_BATCH];

  // generate random numbers between 0 and SIZE_OF_ARRAY 
  for(int i=0; i<SIZE_OF_ARRAY; i++){
      test_array[i]  = rand() % MAX_RAND_VAL;  	
      printf("var[%0d]=%0d\n",i, test_array[i] );
  }

   for(int i=0; i < NUM_BATCH; i++ ){
      int rc;
     // printf("main() : creating thread[%i]\n", i);
      batchinf[i].threadid=i;
      batchinf[i].sizeToProcess = SIZE_OF_ARRAY - i;
      batchinf[i].arrayptr = &(test_array[i]);
      rc = pthread_create(&threads[i], NULL, thread, (void *)&batchinf[i]);    
      if (rc){
         printf("Error:unable to create thread %d",rc);
         exit(-1);
      }
   }
  
  int cnt = 0;
  for(int i=0; i<SIZE_OF_ARRAY-1; i++){
  	for(int j=i+1; j<SIZE_OF_ARRAY; j++){
    	array_file << test_array[i] << "," << test_array[j] << "," << hamming_res[cnt] << std::endl;
  		cnt++;
	}
  }
  for(int i=0; i<SIZE_OF_ARRAY ; i++){
    if(hamming_res[i]<min_hdist)
      min_hdist = hamming_res[i];
  }
  array_file << "min_hamming_dist" << "," << min_hdist << std::endl;
  array_file.close();
   pthread_exit(NULL);

  return 0;
}

