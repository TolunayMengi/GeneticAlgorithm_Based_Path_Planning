# GeneticAlgorithm_Based_Path_Planning
Overview
This is a project intended to find best path created using genetic algorithms in a randomly generated grid.

Problem Definition

The goal of the program is to find the best path from the starting point to the ending point in the 10 to 10 grid with the specified numbers of obstacles for a robot.
Modelling

Creation of 10 to 10 grid contains the specified numbers of obstacles
If there are no obstacles, robot can go through from the point where it is located to east, west, north, south, northeast, northwest, southeast, southwest.

Robot can not go north, if there are obstacles in the northeast, and northwest directions.

Robot can not go south, if there are obstacles in the southeast, and southwest directions.

Robot can not go east, if there are obstacles in the northeast, and southeast directions.

Robot can not go west, if there are obstacles in the northwest, and southwest directions.

Finding Best Path With Genetic Algorithm

Using the genetic algorithm, allows us to find the best results from a randomly generated population. This give us the possibility to search the wide area and we can compare many different ways on this.
The genetic algorithm in the project is coded in the C++ programming language.
The interface of the robot path planning is created in the Phyton programming language.
Operations in genetic algorithm:

Path Coding: Transformation of the  path that the robot will follow into the genetic codes.

Selection Operation: Selecting paths from the population. with the highest fitness and transferring to the next generation. Elitism method is used as selection method. With this method, paths with the highest fitness are selecting and they are transferred to next generation.

Crossover Operation: Two paths are selected from the population and crossed to form a new path. The resulting paths are added to the population.

Uniform crossover method is used as a crossover operation in this project. Genes are taken from one of parent paths with equal possibility.

Mutation Operation: Using by a specific ratio of mutation affects, chromosomes’ varieties would be increase that selected by randomly.
Fitness Function: This function using for calculating value of availability for resolution of elements that in population.
By the time the calculating function of availability, a ratio of distance a number of step a robot’s cope with that obstacle from to target till bump.

Fitness Value = A number of step till bump to obstacle * A distance from that bump to obstacle to target


