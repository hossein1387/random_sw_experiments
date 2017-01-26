
CC = g++
RM = rm -rf

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -DDEBUG=${DEBUG} 

# the build target executable:
TARGET = hamming_distance

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

test:
	@echo "Running test..."
	@make clean
	@make DEBUG=1
	@./$(TARGET)
	@./test.py
clean:
	$(RM) $(TARGET) $(TARGET).dSYM
