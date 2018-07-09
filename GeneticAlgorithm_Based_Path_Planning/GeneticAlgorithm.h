//Genetic algorithm is used to find best path in path population
//includes copy operation to choose new parent paths from child paths using fittness calculation,
//mutation and crossover operations to provide variety of child paths,
//fitness calculation operation to choose best paths from path population.

#include <list>
#include<iostream>
#include "myRobot.h"
#include<time.h>
#include<string>


#pragma once
using namespace std;
class GeneticAlgorithm
{
private:
	list<list<int>> pathPopulation;		//list of pathPopulation
    list<string> truePaths;				//list of truePaths
	bool** myGrid;						//two dimensional bool grid
	int generationNumber = 0;			//generation number of our population
	int popsize = 100;					//population size of our population
	double fitnessValue;		//fitness value of our paths: is set to the worst value for the begining
    string stringTruePath;				//string path for printing

	int startPosition[2];		//x and y coordinate of start position
	int goalPosition[2];		//x and y coordinate of goal position
	int pathLength;				//max lengt of our path

public:
	//constructor function
	GeneticAlgorithm(list<list<int>> _pathPopulation, bool** _myGrid, int _startPosition[2], int _goalPosition[2], int _pathLength);

	//destructor function
	~GeneticAlgorithm();

	void copyOperation();					//copy operation 
	void crossoverMutationOperation();		//crossover and mutation operations
	void fitnessCalculate();				//fittness value calculation operation
	void applyGeneticAlgorithm();			//applying all genetic algorithms
	void printMatrix2D(bool** myGrid);		//print grid to the console screen

    string getStringTruePath();				//getting string path for drawing grid at opengl api
};

