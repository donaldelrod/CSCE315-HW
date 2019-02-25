#!/bin/bash

# Compile all individual function codes using Catch2 defined main for unit testing
echo "Compiling unit testing executables(this may take some time!)..."
make tests
make part1_test
make part2_test
make part4_test
make part5_test
make part7_test
make part8_test

# Execute all tests for unit testing, add your executable down here to add to the unit testing script...
echo "Begin all unit tests..."
#./tests
echo "Testing Part 1..."
./part1_test
echo "Testing Part 2..."
./part2_test
echo "Testing Part 4..."
./part4_test
echo "Testing Part 5..."
./part5_test
echo "Testing Part 7..."
./part7_test
echo "Testing Part 8..."
./part8_test
echo "Testing Parts 3 and 6..."
./tests

echo "Cleaning..."
make clean_tests
make clean
