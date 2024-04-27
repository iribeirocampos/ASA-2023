# <p align="center">Project 1 </p>

## Class Subject and Goals
### Class: [ASA](https://fenix.tecnico.ulisboa.pt/cursos/leic-t/disciplina-curricular/1971853845332785) - Analysis and Synthesis of Algorithms


## Problem Specification - Linear Programming
Professor Natalino Caracol has been hired by the company UbiquityInc, in Rovaniemi, Lapland, to develop a program that will allow them to estimate the maximum profit that can be made from producing and selling of toys during Christmas.

The company produces a set of n wooden toys {x1,..., xn}, where each toy xi has a profit li. In addition to a maximum production limit for each toy due to assembly line restrictions, the company is limited to to a maximum total quantity of toys that can be produced per day, due to restrictions on cutting down the of the boreal forest. Additionally, this Christmas the company decided, in addition to selling each toy individually, to also sell special packages containing three different toys, the profit from which is greater than the sum of the individual profits from the toys that make up the package.

The aim is to tell Rüdolf, UbiquityInc's CEO, what the maximum profit that can be you can make on a daily basis. UbiquityInc will deal with the distribution problem later.

### Input

The input file contains information about the n products, the profit and the company's production capacity for each one, as follows:
- A line containing three integers: t indicating the number of different toys that can be produced, p indicating the number of special packages, and max indicating the maximum number of toys that can be produced per day;
- A list of n lines, where each line contains two integers li and ci indicating the profit and the production capacity of toy i.
- A list of p lines, where each line contains four integers i, j, k, and li jk, indicating the profit li jk of the special package {i, j, k}, and the name of the products i, j, and k that make it up.

Any integers on a line are separated by exactly one blank space and do not other than the end of the line.

### Output
The program should write to the output an integer corresponding to the maximum profit Rüdolf can make each day.

## Compilation
No need, implementation in Python, no compilation needed.

## Requirements
Install pulp package:
```bass
python -m pip install pulp
```

Make sure you have GLPK installed, if not:
``` bash
sudo apt-get install glpk-utils
```

## Run
Run the program using the following command:

```bash
python3 proj3.py
```
