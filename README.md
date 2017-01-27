# random_sw_experiments
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


    [  0] hamming dist 0011 ... 0010( 834440770) and 0101 ... 1000 (1377806480) = 15
    [  1] hamming dist 0011 ... 0010( 834440770) and 0001 ... 1111 ( 477343759) = 19
    [  2] hamming dist 0011 ... 0010( 834440770) and 0110 ... 0000 (1865135968) = 16
    [  3] hamming dist 0011 ... 0010( 834440770) and 0001 ... 0101 ( 521418917) = 18
    [  4] hamming dist 0011 ... 0010( 834440770) and 0110 ... 0011 (1754458259) = 16

Finally to, automatically test if the generated output is correct or not, you can run the test as follow:

    make test

The test result will be saved into a file and it will be read back by python. The results will be checked and verified by the python script. The result will be printed out:

    =============================
    Test pass!
    =============================


##Warning!
Depending on 'SIZE_OF_ARRAY', Assuming n = 'SIZE_OF_ARRAY', total number of calculations will be as follow:

\begin{equation}
\binom{n}{2} = \frac{n!}{2!*(n-2!))}
\end{equation}

## License

All Solutions licensed under MIT License. See LICENSE.txt for further details.


## Copyright

Copyright (c) 2017 [hossein1387](http://hossein1387.github.io/).

