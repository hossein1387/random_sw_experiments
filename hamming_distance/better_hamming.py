#!/usr/bin/python

NUM_BITS= 4
MAX_VAL = (2**NUM_BITS)
GOLDEN_VAL = 10

def hamming(a, b):
        return bin(a^b).count('1')

if __name__ == "__main__":
    for i in range(0, MAX_VAL):
        for j in range(i+1, MAX_VAL):
            print "%s    %s    %0d"%("{0:{fill}4b}".format(i,fill='0'), "{0:{fill}4b}".format(j,fill='0'), hamming(i,j))

