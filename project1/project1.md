# <p align="center">Project 1 </p>

## Class Subject and Goals
### Class: [ASA](https://fenix.tecnico.ulisboa.pt/cursos/leic-t/disciplina-curricular/1971853845332785) - Analysis and Synthesis of Algorithms

## Problem Specification - Dynamic Programing
Engineer João Caracol was hired by the SuperMarble factory to optimize one of its marble slab cutting lines. The line receives a slab of marble that has to be be cut in order to produce pieces with the dimensions required by the factory's customers. A line has a two-disc machine that can cut slabs from one side to the other. 

The cutting process works as follows:
- the sheet is cut vertically or horizontally;
- each of the two new sheets produced re-enters the cutting line or leaves the line, if it if it matches the dimensions of one of the parts to be produced or if it can no longer be converted into a part.

The factory is currently able to dispose of all production, so priority should be given to the manufacture of higher-value parts.
Mr. Caracol's goal is to build a program that, given a marble slab, calculates the maximum value that can be produced.
calculates the maximum value that can be obtained from it by cutting it into pieces corresponding to the dimensions requested by customers. Eng. Caracol can produce several copies of the same piece as it sees fit. More specifically: the line receives a rectangular slab of marble with X × Y dimensions. Caracol also has access to a list of the n types of pieces to be produced, all with different dimensions.
Each type of piece i ∈ {1,...,n} corresponds to a marble rectangle with dimensions ai × bi and is sold at a price pi.

### Input

The input file contains the dimensions of the sheet metal to be cut and the dimensions of the various these values are represented as follows:
- the first line contains two positive integers X and Y, separated by a blank space, which correspond to the dimensions of the sheet metal;
- the second line contains a positive integer n, which corresponds to the number of types of parts that can be produced;
- n lines describing each of the i types of parts that can be produced; 
each line is made up of three positive integers ai , bi and pi separated by a blank space, where ai ×bi correspond to the dimensions of the part type and pi to its price.

### Output
You must write in the output the maximum value that can be obtained from the sheet given as input. input; if no part can be produced, simply print 0.


## Compilation
To compile the program, use the following command:

```bash
g++ -std=c++11 -O3 -Wall proj1.cpp -lm
```
## Run
Run the program using the following command:

```bash
./a
```
