#include "myRobot.h"

//consturctor
myRobot::myRobot(int _startPosition[2], int _goalPosition[2], int _pathLength)
{
	startPosition[0] = _startPosition[0];			//set x coordinate of starting position for specified value
	startPosition[1] = _startPosition[1];			//set y coordinate of starting position for specified value
	goalPosition[0] = _goalPosition[0];				//set x coordinate of goal position  for specified value
	goalPosition[1] = _goalPosition[1];				//set y coordinate of goal position  for specified value
	pathLength = _pathLength;						//set path length for specified value
}

//destructor
myRobot::~myRobot()
{
}

//moves robot to X1 direction
void myRobot::movX1()
{
	coordinateX++;
	coordinateY++;
}

//moves robot to X2 direction
void myRobot::movX2()
{
	coordinateY++;
}

//moves robot to X3 direction
void myRobot::movX3()
{
	coordinateX++;
}

//moves robot to X4 direction
void myRobot::movX4()
{
	coordinateX++;
	coordinateY--;
}

//moves robot to X5 direction
void myRobot::movX5()
{
	coordinateY--;
}

//moves robot to X6 direction
void myRobot::movX6()
{
	coordinateX--;
	coordinateY--;
}

//moves robot to X7 direction
void myRobot::movX7()
{
	coordinateX--;
}

//moves robot to X8 direction
void myRobot::movX8()
{
	coordinateX--;
	coordinateY++;
}

//returns robot's x coordinate
int myRobot::getCoordinateX()
{
	return coordinateX;
}

//sets robot's x coordinate
void myRobot::setCoordinateX(int _coordinateX)
{
	coordinateX = _coordinateX;
}

//returns robot's y coordinate
int myRobot::getCoordinateY()
{
	return coordinateY;
}

//sets robot's y coordinate
void myRobot::setCoordinateY(int _coordinateY)
{
	coordinateY = _coordinateY;
}

//gets myGrid and path object to try path in given grid
bool myRobot::tryThePath(bool** myGrid,list<int> path)
{
	bool isWayConvenient = true;	//holds path's suitability variable
	bool isPathFound = false;			//is held for exit from function if path found

	//Sets start position of myrobot
	setCoordinateX(startPosition[0]);
	setCoordinateY(startPosition[1]);

	//try every int value in list path
	for (auto v : path)
	{
		switch (v)
		{
		case 1:	//if robot goes X1 direction
		{
			movX1();//Update robots coordinate variable
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] ||//if my robot's x coordinate isn't in suitable range for my grid
				coordinateY < startPosition[1] || coordinateY > goalPosition[1] ||//if my robot's y coordinate isn't in suitable range for my grid
				myGrid[coordinateX][coordinateY] == true ||//if there is an obstacle in the coordinate reached
				(myGrid[coordinateX-1][coordinateY] == true && myGrid[coordinateX][coordinateY-1] == true))//for examle: north and west coordinates aren't empy both when going northwest
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])//if reached point is goal point
				isPathFound = true;
		}
			
			break;
		case 2://if robot goes X2 direction : for more details look case 1
		{
			movX2();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 3://if robot goes X3 direction : for more details look case 1
		{
			movX3();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 4://if robot goes X4 direction : for more details look case 1
		{
			movX4();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX - 1][coordinateY] == true && myGrid[coordinateX][coordinateY + 1] == true))
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 5://if robot goes X5 direction : for more details look case 1
		{
			movX5();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 6://if robot goes X6 direction : for more details look case 1
		{
			movX6();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX + 1][coordinateY] == true && myGrid[coordinateX][coordinateY + 1] == true))
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 7://if robot goes X7 direction : for more details look case 1
		{
			movX7();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true)
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		case 8://if robot goes X8 direction : for more details look case 1
		{
			movX8();
			if (coordinateX < startPosition[0] || coordinateX > goalPosition[0] || coordinateY < startPosition[1] || coordinateY > goalPosition[1] || myGrid[coordinateX][coordinateY] == true || (myGrid[coordinateX + 1][coordinateY] == true && myGrid[coordinateX][coordinateY - 1] == true))
				isWayConvenient = false;
			else if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
		}
			break;
		default:
			break;
		}
		if (isWayConvenient == false)//if wat is not suitable exit
			break;
	}
	if (isPathFound == true)
	{
		cout << "Path Found: True" << endl;
		
	}
	return isPathFound;
}

double myRobot::calculateFitnessValueOfPath(bool ** myGrid, list<int> path)//calculate fitness value of path for finding best path
{
	bool isWayConvenient = true;//holds if path tried is suitable

	int fitnessV1 = 0;			//first value of fitness calculation:
								//number of moves the robot has made

	double fitnessV2;		//second value of fittness calculation:
								//the distance of robor from the last coordinate 
								//before bump into obstacles to goal point
	//set start position of robot
	setCoordinateX(startPosition[0]);			
	setCoordinateY(startPosition[1]);

	double fitnessValue;		//calculated with fitnessV1 and fitnessV2

	for (auto v : path)			//for everty int value in list path
	{
		switch (v)
		{
		case 1://X1 direction
		{
			movX1();
			//if movement is possible
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && coordinateY <= goalPosition[1] && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX - 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;		//increase fitnessV1 value
			else					//else set isWatConvenient false
				isWayConvenient = false;
		}
			break;
		case 2://X2 direction: for more information look case 1
		{
			movX2();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 3://X3 direction: for more information look case 1
		{
			movX3();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 4://X4 direction: for more information look case 1
		{
			movX4();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX - 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 5://X5 direction: for more information look case 1
		{
			movX5();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == true)
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 6://X6 direction: for more information look case 1
		{
			movX6();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX + 1][coordinateY] == false || myGrid[coordinateX][coordinateY + 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
		}
			break;
		case 7://X7 direction: for more information look case 1
			movX7();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false)
				fitnessV1++;
			else
				isWayConvenient = false;
			break;
		case 8://X8 direction: for more information look case 1
		{
			movX8();
			if (coordinateX >= startPosition[0] && coordinateX <= goalPosition[0] && coordinateY >= startPosition[1] && myGrid[coordinateX][coordinateY] == false && (myGrid[coordinateX + 1][coordinateY] == false || myGrid[coordinateX][coordinateY - 1] == false))
				fitnessV1++;
			else
				isWayConvenient = false;
			break;
		}
		default:
			break;
		}
		if (isWayConvenient == false)//if way is not convenient stop operation
			break;
	}
	//The best path has the smallest value. This is the rule of calculation fitness value in genetic algorithm.

	// the distance of robot from the last coordinate before bump into obstacles to goal point
    fitnessV2 = sqrt(((goalPosition[0] + 1) - coordinateX)*((goalPosition[0] + 1) - coordinateX) + ((goalPosition[1] + 1) - coordinateY)*((goalPosition[1] + 1) - coordinateY));
	fitnessValue = fitnessV1*fitnessV2;		//our fitness value calculates with multiplication of fitnessV1 and fitnessV2
	return fitnessValue;					//return fitness value calculated
}

void myRobot::printMatrix2D(bool ** myGrid)	//function that prints our grid on the console screen
{
	cout << "10x10 Grid: " << endl;
	for (int j = 9; j >= 0; j--)
	{
		for (int i = 0; i < 10; i++)
			printf("(%d,%d)%d  ", i, j, myGrid[i][j]);
		printf("\n");
	}
}

// calculates string coordinates of true paths from start point to goal point and returns
string myRobot::calculateTruePath(bool ** myGrid, list<int> path)
{
	int length = 0;				//length of our path
	bool isPathFound = false;	//hold variable about if path found

	//set start position of our robot
	setCoordinateX(startPosition[0]);
	setCoordinateY(startPosition[1]);

	cout << "(" << coordinateX << "," << coordinateY << ") ";//ptint current position of our robot

    string stringPath; //definition of our string path

	for (auto v : path)	//for all int variables in list path
	{
		switch (v)
		{
		case 1:	//X1 direction
		{
			movX1();	//move X1
			cout << "1->(" << coordinateX << "," << coordinateY << ") ";//print current position of our robot
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])//check if robot reached goal position
				isPathFound = true;//if yes, set true

            stringPath.append(to_string(coordinateX));//append coordinate x to stringPath
            stringPath.append(to_string(coordinateY));//append coordinate y to stringPath
		}

		break;
		case 2://X2 direction: for more information look case 1
		{
			movX2();
			cout << "2->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 3://X3 direction: for more information look case 1
		{
			movX3();
			cout << "3->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 4://X4 direction: for more information look case 1
		{
			movX4();
			cout << "4->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 5://X5 direction: for more information look case 1
		{
			movX5();
			cout << "5->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 6://X6 direction: for more information look case 1
		{
			movX6();
			cout << "6->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 7://X7 direction: for more information look case 1
		{
			movX7();
			cout << "7->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		case 8://X8 direction: for more information look case 1
		{
			movX8();
			cout << "8->(" << coordinateX << "," << coordinateY << ") ";
			if (coordinateX == goalPosition[0] && coordinateY == goalPosition[1])
				isPathFound = true;
            stringPath.append(to_string(coordinateX));
            stringPath.append(to_string(coordinateY));
		}
		break;
		default:
			break;
		}
		if (isPathFound == true)
			break;
	}

	cout << endl;
	printMatrix2D(myGrid);	//print our grid to console screen
    return stringPath;		//return stringPath
}
