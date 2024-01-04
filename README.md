# Breadth-First-Search-BFS-and-Dijkstra-s-algorithm
A programing assigment I am proud of.

Files include bfs (breath first search algorithm and its supporting parts), dijkstra (Dijkstra's algorithm and its supporting parts), queue (implementation of the queue data structure), the main files and the Makefile. Most consist of the c program file, the header file, as well as an executable file.

This program uses these algorithms create the shortest travel time between a network of cities connected by railways under different constraints.

Overview:
This program involves a network of N cities, labeled from 0 to N-1, connected by a railway system. The rail links given in the format of triplets (u, v, w), where 'u' is the origin city, 'v' is the destination city, and 'w' represents the journey time in hours from city 'u' to city 'v'. 

Objectives:
Uniform Travel Time with BFS
With the assumption that the journey time between any two directly linked cities is constant (1 hour), the program utilizes the Breadth-First Search (BFS) technique to determine the minimum time required for a traveler to reach city 'N-1' from city '0'.
Goal: Apply the BFS method to identify the shortest route based on the count of cities crossed.
Varied Travel Time with Dijkstra's Algorithm
Taking into account the actual travel times 'w' between cities, employ Dijkstra's algorithm to find the minimum journey time for a traveler moving from city '0' to city 'N-1'.
Goal: Utilize Dijkstra's algorithm to ascertain the quickest path considering travel duration.


The input is read from the stdin here is an example:

    city.in
    0
    1
    3
    
The first line specifies a filename that contains connections between cities. The following numbers are commands for specific operations:
  '0' instructs the program to perform the BFS (Breadth-First Search) algorithm.
  '1' is a directive to run Dijkstra's algorithm.
  '3' signals the program to terminate.

The city.in file details city connections and is structured as follows:

    5
    6
    0,1,4
    0,2,2
    1,2,1
    1,3,10
    2,4,3
    3,4,1

  Where '5' indicates the total number of cities.
  '6' represents the number of links between them.
  Each line like '0,1,4' denotes a time of '4' between cities '0' and '1'. 


