#include <time.h>       /* time */
#include <string>
#include <bitset>

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
            printf("hamming dist %s(%4d) and %s(%4d) = %0d\n", std::bitset<32>(tab[i]).to_string().c_str(), 
            	   tab[i], std::bitset<32>(tab[j]).to_string().c_str(), tab[j], popcount(hamming_dist));
			if(hamming_dist==0) // if there is a hamming distance of zero, noone can beat it, return! 
				return 0;
			if(hamming_dist<min_hamming_dist)
				min_hamming_dist = hamming_dist;
		}
	}

	return min_hamming_dist;
}
