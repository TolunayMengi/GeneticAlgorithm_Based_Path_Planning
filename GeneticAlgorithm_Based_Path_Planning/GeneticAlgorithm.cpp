#include "GeneticAlgorithm.h"

//constructor
GeneticAlgorithm::GeneticAlgorithm(list<list<int>> _pathPopulation, bool** _myGrid, int _startPosition[2], int _goalPosition[2], int _pathLength)
{
	//auto it = _pathPopulation.begin();	//set iterator1 as parent1 index
	//for (int i = 0; i < _pathPopulation.size(); i++)
	//	pathPopulation.push_back(*it);
	pathPopulation = _pathPopulation;		//set pathPopulation
	myGrid = _myGrid;						//set myGrid
	startPosition[0] = _startPosition[0];	//set x coordinate of start position
	startPosition[1] = _startPosition[1];	//set y coordinate of start position
	goalPosition[0] = _goalPosition[0];		//set x coordinate of goal position
	goalPosition[1] = _goalPosition[1];		//set y coordinate of goal position
	pathLength = _pathLength;				//set path lengt for the specied value
	fitnessValue = (pathLength * sqrt(10 * 10));//set starting fitness value as the worst value
}

//destructor
GeneticAlgorithm::~GeneticAlgorithm()
{
}

//calculates fitness value with selecting fitness value of path which has best fitness value
void GeneticAlgorithm::fitnessCalculate()
{
	myRobot robot(startPosition, goalPosition, pathLength);
	for (auto v0 : pathPopulation)//for all paths in pathPopulation
	{
		if (fitnessValue > robot.calculateFitnessValueOfPath(myGrid, v0))//if current fitness value bigger than new path's fitness value
			fitnessValue = robot.calculateFitnessValueOfPath(myGrid, v0);//select new path's fittness value as deffault fitness value
	}
}


//choose new parent paths from child paths using fittness calculation
void GeneticAlgorithm::copyOperation()
{
	myRobot robot(startPosition, goalPosition, pathLength);						//create a myRobot objet to use calculateFitnessValueOfPath function
	list<list<int>> newPathPopulation;											//creates newPathPopulation for choosing new parent paths
	for (auto v0 : pathPopulation)	//for every elemnt of 'old' pathPopulation
	{
		if (robot.calculateFitnessValueOfPath(myGrid, v0) <= fitnessValue)	//if paths fitness's value is not larger than deffault fittness value
			newPathPopulation.push_back(v0);								//add path to new pathpopulation
	}
	pathPopulation = newPathPopulation;		//set new path population
}

void GeneticAlgorithm::crossoverMutationOperation()
{
	list<int> parent1, parent2, child;	//create new lists for parents and child
	int ppSize = pathPopulation.size();	//get pathPopulation's size
	int pN1, pN2;						//indexes of parent1 and parent2


    pN1 = rand() % ppSize;				//select random index for parent1
    pN2 = rand() % ppSize;				//select random index for parent2



    auto it1 = std::next(pathPopulation.begin(), pN1);	//set iterator1 as parent1 index
	parent1 = *it1;										//set parent1 as path iterator pointed
    auto it2 = std::next(pathPopulation.begin(), pN2);	//set iterator2 as parent1 index
	parent2 = *it1;										//set parent2 as path iterator pointed
    int pSize = parent1.size();							//get size of parent1 or parent2(both of their sizes are equal)





    for (int i = 0; i < pSize; i++)			//for int i from 0 to pSize
    {
        int posibility = rand() % 1000;				//create a random number for selecting operation
		
        if (posibility < 445)						//if number is between 0 and 444
		{
			auto it3 = std::next(parent1.begin(), i);	//set iterator to paths i'th cromozom of parent 1
			int cromozom = *it3;
			child.push_back(cromozom);					//add chromozom to child paths gene
		}
        else if (posibility <900)					//if number is between 445 and 899
		{
            auto it3 = std::next(parent2.begin(), i);	//set iterator to paths i'th cromozom of parent 2
			int cromozom = *it3;
			child.push_back(cromozom);					//add chromozom to child paths gene
		}
		else			//else Mutation operation
		{
			int mutatedGene = (rand() % 8) + 1;		//create a mutate chromozom between 1 and 8
			child.push_back(mutatedGene);			//add chromozom to child paths gene
		}
	}

	pathPopulation.push_back(child);			//add newa child path to path population
}



void GeneticAlgorithm::applyGeneticAlgorithm()	//applying genetic algorithm
{
	bool pathFound = false;			//define bool to figure out if path found and set it false for the first time
	myRobot robot(startPosition, goalPosition, pathLength);	//create myrobot object to try path
    while (pathFound == false && generationNumber<=1000)	//as long as the path not found
	{
		fitnessCalculate();		//calculate fitness
		copyOperation();		//do copy operation

		while (pathPopulation.size() < popsize)	//while pathPopulation's size smaller than popsize
		{
			crossoverMutationOperation();	//do crossoverMutationOperation to increase pathPopulation
		}
		cout << endl << "Generation number: " << generationNumber << endl;	//print generation number of our path population
		for (auto v0 : pathPopulation)	//for all paths in our path population
		{
			if (robot.tryThePath(myGrid, v0) == true)	//if path is found
			{
				pathFound = true;	//set pathFound true
				stringTruePath = robot.calculateTruePath(myGrid, v0);	//set string true path for draw at screen
                truePaths.push_back(stringTruePath);					//add stringtruepath to truePaths list
			}

			cout << "Path: ";
			for (auto v1 : v0)	//for all alements of finding path
			cout << v1 << " ";	//print screen
			cout << endl;	
		}
		generationNumber++;		//increase generation number
	}
    std::list<string>::iterator it = truePaths.begin();
    stringTruePath = *it;
    for (auto v0 : truePaths)	//find the shortest path in path pupulation
    {
        if(stringTruePath.size()>it->size())
            stringTruePath=v0;
        it++;
    }

}

void GeneticAlgorithm::printMatrix2D(bool ** myGrid)	//print grid in 2D Matrix
{
	cout << "10x10 Grid: " << endl;
	for (int j = 9; j >= 0; j--)
	{
		for (int i = 0; i < 10; i++)
			printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
		printf("\n");
    }
}

string GeneticAlgorithm::getStringTruePath()//get stringTruePath
{
    return stringTruePath;
}

