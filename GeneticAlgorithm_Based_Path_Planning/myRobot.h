#include <list>
#include<iostream>
#include<math.h>
#include<string>


#pragma once
using namespace std;
class myRobot
{
private:
	//Coordinate variables of my robot:
	int coordinateX;			//x coordinate of our robot
	int coordinateY;			//y coordinate of our robot
	int startPosition[2];		//x and y coordinate of start position
	int goalPosition[2];		//x and y coordinate of goal position
	int pathLength;				//max lengt of our path
public:
	//constructor and deconstructor functtions of myrobot class
	myRobot(int _startPosition[2], int _goalPosition[2], int _pathLength);
	~myRobot();

	// X1, X2, X3, X4, X5, X6, X7, X8 veriables are directions that my robot can move.
	void movX1();//northeast
	void movX2();//north
	void movX3();//east
	void movX4();//southeast
	void movX5();//south
	void movX6();//southwest
	void movX7();//west
	void movX8();//northwest

	//Getters and Setters of coordinate variables
	int getCoordinateX();
	void setCoordinateX(int _coordinateY);
	int getCoordinateY();
	void setCoordinateY(int _coordinateY);

	//function that tries paths if they are suitable
	bool tryThePath(bool** myGrid,list<int> path);

	//Calculates fitness value of path for genetic algorithm
	double calculateFitnessValueOfPath(bool** myGrid, list<int> path);

	//ptints matrix in console screen
	void printMatrix2D(bool** myGrid);

	//calculates string coordinates of true paths from start point to goal point and returns
    string calculateTruePath(bool** myGrid, list<int> path);

};
