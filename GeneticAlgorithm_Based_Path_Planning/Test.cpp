#include "myRobot.h"
#include "GeneticAlgorithm.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <list>
#include<Windows.h>

#include<glut.h>
#include<cmath>

using namespace std;

int startPosition[2] = { 0,0 };		//starting position of our robot - if you want different location, set different values
int goalPosition[2] = { 9,9 };		//goal position of our robot - if you want different location, set different values
int pathLength = 30;				//max lengt of our path
int numberOfObstacles = 15;			//number of obstacles in the grid. - You can chan value

bool** createGrid(int numberOfObstacles, int startState[2], int goalState[2]);
list<int> createInitialPopulation(int startPosition[2], int goalPosition[2], int pathLength);
void printMatrix2D(bool** myGrid);
void printInitialPath(list<int> path);

void Draw();
void Initialize();

bool** myGrid;
string pathTrue;

int main(int iArgc, char** cppArgv)
{
    
    list<list<int>> pathPopulation;		//list of path population
    myRobot robot(startPosition, goalPosition, pathLength);		//create myRobot object to try paths
    myGrid = createGrid(numberOfObstacles, startPosition, goalPosition);		//create grid map using given values


    list<int> initialPath = createInitialPopulation(startPosition, goalPosition, pathLength);	//create first parent path
    pathPopulation.push_front(initialPath);		// add first parent path to pathPupulation
    GeneticAlgorithm GA(pathPopulation, myGrid, startPosition, goalPosition, pathLength);		//create genetic algorithm object
    printMatrix2D(myGrid);	//print true path in 2D matrix
    printInitialPath(initialPath);	//print string coordinate value of true path
    cout<<"Is the path convinent: "<<robot.tryThePath(myGrid, initialPath)<<endl;
    GA.applyGeneticAlgorithm();		//apply genetic algorithm


    pathTrue=GA.getStringTruePath();	//get string true path
    cout<<"TRU"<<pathTrue;				//print string true path coordinates

	


	
	//**********drawing with GLUT library************

	glutInit(&iArgc, cppArgv);			//glutInit function call
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode
	glutInitWindowSize(500, 500);		//set window size in pixels
	glutInitWindowPosition(200, 200);	//set window starting position
	glutCreateWindow("Robot Path Planning");	//set window name
	Initialize();								//Init function call
	glutDisplayFunc(Draw);						//Draw function call
	glutMainLoop();


	//***********************************************/

    system("pause");			//system paused
    return 0;					//returns 0
}

//function that creating Grid map specifying obstacles position
bool** createGrid(int numberOfObstacles, int startState[2], int goalState[2])
{
    int i, j, index1, index2;
    bool** myGrid;
    myGrid = new bool*[10];

    for ( i = 0; i < 10; i++)//create 2D matric with for loop
    {
        myGrid[i] = new bool[10];
        for(int j= 0; j < 10; j++)
            myGrid[i][j] = false;
    }

    int k=0;
    srand(time(NULL));	//we use this function to create random number at the next loop

    for (int i = 0; i < numberOfObstacles; i++)	//int i from 0 to numberOfObstacles
    {
        k++;
        j = rand() % 100;	//create random number between 0 and 99(index number in grid map)
        index1 = j / 10;	//x coordinate of our obstacle
        index2 = j % 10;	//y coordinate of our obstacle

		//if we create obstacle with different value with other obstacle locations or starting point or goal point
        if (myGrid[index1][index2] != true && ((index1 != startState[0] || index2 != startState[1]) && (index1 != goalState[0] || index2 != goalState[1])))
        {
            myGrid[index1][index2] = true;//set TRUE:obstacle otherwise FALSE:space
        }
        else
            i--; //otherwise decrease i and do dame operation again
    }

    return myGrid;	//return myGrid 
}

//function that creates first path of our path population - Initial path - for the best solution
//this function determines the best path for the air distance
list<int> createInitialPopulation(int startPosition[2],int goalPosition[2], int pathLength)
{
    list<int> path;

    int horizontalDistance, verticalDistance;
    horizontalDistance = goalPosition[0] - startPosition[0];	//calculate horizontal distance: it can be negative value
    verticalDistance = goalPosition[1] - startPosition[1];		//calculate vertical distance: it can be negative value

	//do while operations to reach the goal point
    while (horizontalDistance > 0 && verticalDistance > 0)	//if goal point at northeast
    {
        path.push_back(1);		//go 1(northeast) direction
        horizontalDistance--;	//decrease horizontal distance
        verticalDistance--;		//decrease vertical distance
    }
    while (horizontalDistance < 0 && verticalDistance > 0)	//if goal point at northwest
    {
        path.push_back(8);		//go 8(northwest) direction
		horizontalDistance++;	//increase horizontal distance
		verticalDistance--;		//decrease vertical distance
    }
    while (horizontalDistance > 0 && verticalDistance < 0)	//if goal point at southeast
    {
        path.push_back(4);		//go 4(southeast) direction
		horizontalDistance--;	//decrease horizontal distance
		verticalDistance++;		//increase vertical distance
    }
    while (horizontalDistance < 0 && verticalDistance < 0)	//if goal point at southwest
    {
        path.push_back(6);		//go 6(southwest) direction
		horizontalDistance++;	//increase horizontal distance
		verticalDistance++;		//increase vertical distance
    }
    while (horizontalDistance > 0)	//if goal point at east
    {
        path.push_back(3);		//go 3(east) direction
		horizontalDistance--;	//decrease horizontal distance
    }
    while (horizontalDistance < 0)	//if goal point at west
    {
        path.push_back(7);		//go 7(west) direction
		horizontalDistance++;	//increase horizontal distance
    }
    while (verticalDistance > 0)	//if goal point at north
    {
        path.push_back(2);		//go 2(north) direction
		verticalDistance--;		//decrease vertical distance
    }
    while (verticalDistance < 0)	//if goal point at south
    {
        path.push_back(5);		//go 5(south) direction
		verticalDistance++;		//increase vertical distance
    }

	int randomIndex;
	while (path.size() < pathLength) //while size of path readh to pathLength value select random path inside path and add back
	{
		randomIndex = (rand() % path.size());
		list<int>::iterator it = path.begin();
		for (int i = 0; i < randomIndex; i++) {
			++it;
		}
		path.push_back(*it);
	}
    return path;
}

void printMatrix2D(bool** myGrid)	//funciton thah print 2D matrix
{
    cout << "10x10 Grid: " << endl;
    for (int j = 9; j >= 0; j--)
    {

        for (int i = 0; i < 10; i++)
            printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
        printf("\n");
    }
}

void printInitialPath(list<int> path)	//printing initial path
{
    cout << "Initial Path: ";
    for (auto v : path)
        cout << v << " ";
    cout << endl;
}

//******************** OPEN GL **********************
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);		//begin drawing lines of grid map
							//I determine the edge length as 0.08 * screen length
		//GRID ROWS			
		glVertex3f(0.1, 0.1, 0.0);			
		glVertex3f(0.9, 0.1, 0.0);		
		glVertex3f(0.1, 0.18, 0.0);		
		glVertex3f(0.9, 0.18, 0.0);		
		glVertex3f(0.1, 0.26, 0.0);		
		glVertex3f(0.9, 0.26, 0.0);		
		glVertex3f(0.1, 0.34, 0.0);		
		glVertex3f(0.9, 0.34, 0.0);		
		glVertex3f(0.1, 0.42, 0.0);		
		glVertex3f(0.9, 0.42, 0.0);		
		glVertex3f(0.1, 0.50, 0.0);		
		glVertex3f(0.9, 0.50, 0.0);		
		glVertex3f(0.1, 0.58, 0.0);		
		glVertex3f(0.9, 0.58, 0.0);		
		glVertex3f(0.1, 0.66, 0.0);		
		glVertex3f(0.9, 0.66, 0.0);		
		glVertex3f(0.1, 0.74, 0.0);		
		glVertex3f(0.9, 0.74, 0.0);		
		glVertex3f(0.1, 0.82, 0.0);		
		glVertex3f(0.9, 0.82, 0.0);		
		glVertex3f(0.1, 0.9, 0.0);		
		glVertex3f(0.9, 0.9, 0.0);	

		//GRID COLUMNS
		glVertex3f(0.1, 0.1, 0.0);
		glVertex3f(0.1, 0.9, 0.0);
		glVertex3f(0.18, 0.1, 0.0);
		glVertex3f(0.18, 0.9, 0.0);
		glVertex3f(0.26, 0.1, 0.0);
		glVertex3f(0.26, 0.9, 0.0);
		glVertex3f(0.34, 0.1, 0.0);
		glVertex3f(0.34, 0.9, 0.0);
		glVertex3f(0.42, 0.1, 0.0);
		glVertex3f(0.42, 0.9, 0.0);
		glVertex3f(0.50, 0.1, 0.0);
		glVertex3f(0.50, 0.9, 0.0);
		glVertex3f(0.58, 0.1, 0.0);
		glVertex3f(0.58, 0.9, 0.0);
		glVertex3f(0.66, 0.1, 0.0);
		glVertex3f(0.66, 0.9, 0.0);
		glVertex3f(0.74, 0.1, 0.0);
		glVertex3f(0.74, 0.9, 0.0);
		glVertex3f(0.82, 0.1, 0.0);
		glVertex3f(0.82, 0.9, 0.0);
		glVertex3f(0.9, 0.1, 0.0);
		glVertex3f(0.9, 0.9, 0.0);
		glEnd();

		//START POINT		//drawing starting point as square in given location
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUAD_STRIP);
		glVertex3f((0.1 + 0.08 * startPosition[0]), (0.102 + 0.08 * startPosition[1]), 0.0);
		glVertex3f((0.178 + 0.08 * startPosition[0]), (0.102 + 0.08 * startPosition[1]), 0.0);
		glVertex3f((0.1 + 0.08 * startPosition[0]), (0.18 + 0.08 * startPosition[1]), 0.0);
		glVertex3f((0.178 + 0.08 * startPosition[0]), (0.18 + 0.08 * startPosition[1]), 0.0);
		glEnd();

		//GOAL POINT		//drawing goal point as square in given location
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_QUAD_STRIP);
		glVertex3f((0.1 + 0.08 * goalPosition[0]), (0.102 + 0.08 * goalPosition[1]), 0.0);
		glVertex3f((0.178 + 0.08 * goalPosition[0]), (0.102 + 0.08 * goalPosition[1]), 0.0);
		glVertex3f((0.1 + 0.08 * goalPosition[0]), (0.18 + 0.08 * goalPosition[1]), 0.0);
		glVertex3f((0.178 + 0.08 * goalPosition[0]), (0.18 + 0.08 * goalPosition[1]), 0.0);
		glEnd();

		//DRAW OBSTACLES	//drawing obstacles as square in given locations
		glColor3f(1.0, 0.0, 0.0);
		int i, j;
		for (i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				if (myGrid[i][j] == true)
				{
					glBegin(GL_QUAD_STRIP);
					glVertex3f(0.1 + i * 0.08, 0.102 + j * 0.08, 0.0);
					glVertex3f(0.178 + i * 0.08, 0.102 + j * 0.08, 0.0);
					glVertex3f(0.1 + i * 0.08, 0.18 + j * 0.08, 0.0);
					glVertex3f(0.178 + i * 0.08, 0.18 + j * 0.08, 0.0);
					glEnd();
				}
		}

		//DRAW PATH		//drawing path with lines
		glColor3f(1.0, 0.0, 1.0);
		int coordinateXOld, coordinateYOld, coordinateXNew, coordinateYNew;
		double coordinate[2] = { 0.14, 0.14 };
		std::string::iterator it;

		coordinateXOld = startPosition[0];
		coordinateYOld = startPosition[1];

		while (pathTrue.length() != 0) {
			it = pathTrue.begin();
			coordinateXNew = (int)*it - 48;
			pathTrue.erase(pathTrue.begin());

			it = pathTrue.begin();
			coordinateYNew = (int)*it - 48;
			pathTrue.erase(pathTrue.begin());

			glBegin(GL_LINES);
			glVertex3f(0.14 + coordinateXOld * (0.08), 0.14 + coordinateYOld * (0.08), 0.0);
			glVertex3f(0.14 + coordinateXNew * (0.08), 0.14 + coordinateYNew * (0.08), 0.0);
			glEnd();

			coordinateXOld = coordinateXNew;
			coordinateYOld = coordinateYNew;
		}
		

	glFlush();
}

//GLUT initialize function
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
