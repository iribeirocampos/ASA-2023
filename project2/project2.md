# <p align="center">Project 1 </p>

## Class Subject and Goals
### Class: [ASA](https://fenix.tecnico.ulisboa.pt/cursos/leic-t/disciplina-curricular/1971853845332785) - Analysis and Synthesis of Algorithms


## Problem Specification - SCCs
Professor João Caracol is carrying out a study for the government taskforce responsible for study of communicable diseases in Portugal. 
The taskforce is particularly interested in the the topic of disease transmission among the Portuguese population, in order to study the best
intervention mechanisms to contain the spread of disease.

To this end, Professor João Caracol had access to data from the TugaNet social network, which he believes is representative of the real social interactions between individuals in the Portuguese population.
So, in order to study the worst case scenario for the spread of a given infection in Portugal, Professor João Caracol wants to understand the greatest number of jumps a given disease can make.
However, given the density of Portuguese cities, Professor João Caracol decided to make a simplifying assumption: individuals who know each other directly or indirectly directly or indirectly, become infected instantly.

### Input

The input file contains information about the TugaNet network, which is defined as a directed graph of relationships between two individuals, as follows:
- A line containing two integers: the number n of individuals (n ≥ 2), and the number of relationships m to indicate (m ≥ 0);
- A list in which each line i contains two integers x and y, representing that individual x knows individual y.
Any integers on a line are separated by exactly one blank space, and do not other than the end of the line.
Assume that input graphs are directed (potentially) cyclic.

### Output
The program should write to the output an integer s corresponding to the maximum number of jumps a disease can make on the TugaNet network.

## Compilation
To compile the program, use the following command:

```bash
g++ -std=c++11 -O3 -Wall proj2.cpp -lm
```
## Run
Run the program using the following command:

```bash
./a
```
