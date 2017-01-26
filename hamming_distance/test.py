#!/usr/bin/python
__INPUT_FILE__ = "array.txt"
array = []
def hamming(a, b):
    return bin(a^b).count('1')

if __name__ == "__main__":
	with open(__INPUT_FILE__) as f:
		for line in f:
			array.append(int(line))



