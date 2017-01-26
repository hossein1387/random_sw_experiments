# random_experiments
# What is this?

This repo contains my random experiments designing software.


#Finding Minimum Hamming Distance Project:

In this project, I have implemented an algorithm to compute the minimum hamming distance of 32 bits integers. The project comes with an automatic test script written in python. First you need to make sure you have cloned this repository:

    git clone https://github.com/hossein1387/random_sw_experiments.git
    cd random_sw_experiments/hamming_distance

Then you can build and run the algorithm seperately by:
    
    make 
    ./hamming_distance

This will build the a binary that computes the minimum hamming distance of an array that was randomly generated. The number of tests (array elements) is controlled by test macro defined as 'SIZE_OF_ARRAY'. 
To print out the results, you can run the makefile as follow:

    make DEBUG=1
    ./hamming_distance

This will create the binary and by executing the binary, it will print out all the generated numbers and their corresponding hamming distance:

[  0] hamming dist 00110001101111001000111001000010( 834440770) and 01010010000111111010100010010000(1377806480) = 15
[  1] hamming dist 00110001101111001000111001000010( 834440770) and 00011100011100111011000000001111( 477343759) = 19
[  2] hamming dist 00110001101111001000111001000010( 834440770) and 01101111001010111011011101100000(1865135968) = 16
[  3] hamming dist 00110001101111001000111001000010( 834440770) and 00011111000101000011100010100101( 521418917) = 18
[  4] hamming dist 00110001101111001000111001000010( 834440770) and 01101000100100101110100010010011(1754458259) = 16

Finally to, automatically test if the generated output is correct or not, you can run the test as follow:

    make test

The test result will be saved into a file and it will be read back by python. The results will be checked and verified by the python script. The result will be printed out:

    =============================
    Test pass!
    =============================


## License

All Solutions licensed under MIT License. See LICENSE.txt for further details.


## Copyright

Copyright (c) 2017 [hossein1387](http://hossein1387.github.io/).

