#!/usr/bin/python
__INPUT_FILE__ = "array.txt"
def hamming(a, b):
        return bin(a^b).count('1')

if __name__ == "__main__":
    expected_min_hamming_distance = 33 # Result can't be bigger than this    
    ERROR = False
    with open(__INPUT_FILE__) as f:
        for line in f:          
            pairs    = line.replace(' ','').split(',')
            if(pairs[0] == "min_hamming_dist"):
                actual_min_hamming_distance = int(pairs[1])
            else:
                a        = int(pairs[0])            
                b        = int(pairs[1])            
                actual   = int(pairs[2])            
                expected = hamming(a, b)
                if(expected != actual):             
                    print "ERROR: Hamming distance of %0d and %0d is %0d not %0d"%(a, b, expected, actual)
                    ERROR = True
                if(expected<expected_min_hamming_distance):
                    expected_min_hamming_distance = expected

    if(actual_min_hamming_distance!=expected_min_hamming_distance):
        ERROR = True
        print "min humming distance is %0d not %0d"%(expected_min_hamming_distance, actual_min_hamming_distance)

    if(ERROR):
        print "============================="
        print "Test fail!"
        print "============================="
    else:
        print "============================="
        print "Test pass!"
        print "============================="
