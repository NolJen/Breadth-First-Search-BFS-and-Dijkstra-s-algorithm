#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Task 2: Varied Travel Time with Dijkstra's Algorithm

//Now, consider the actual travel times `w` between cities. Use Dijkstra's algorithm to compute the minimum travel time needed for a traveler to go from city `0` to city `N-1`.

//Objective: Implement Dijkstra's algorithm to find the shortest path in terms of travel time.
//Note: You can either use array or heap to implement Dijkstra's algorithm. 

// Function to perform Dijkstra's algorithm on a graph represented as an adjacency matrix
void dijkstra(int **graph, int num_cities, int src) {
	int distances[num_cities];		//store the shortest path
	int shortestPath[num_cities];		//include num_cities into the shortest path tree set

	//initialize the distance to be infinite and the shortest path to be false (denoted by INT_MAX and 0 respectivly as based on the notes of lecture)
	for (int i = 0; i < num_cities; i++) {
		distances[i] = INT_MAX;
		shortestPath[i] = 0;
	}

	distances[src] = 0; //set the distance of the source vertex from itself is always 0

	//find the shortest path
	for (int count = 0; count < num_cities - 1; count++) {
		int min = INT_MAX, min_index;

		for (int v = 0; v < num_cities; v++) {
			if (shortestPath[v] == 0 && distances[v] <= min) {
				min = distances[v];
				min_index = v;
			}
		}

		//mark vertex as processed
		int u = min_index;
		shortestPath[u] = 1;

		//update the distance of the adjcent vertices
		for (int v = 0; v < num_cities; v++) {
			if (!shortestPath[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
				distances[v] = distances[u] + graph[u][v];
			}
		}
	}

	int destination = num_cities - 1;
	if (distances[destination] != 0) {
		//print the shortest distance to the desitnaiton city
		printf("%d\n", distances[destination]);
	} else {
		//if the destination city is unreachable, the funciton oupts -1
		printf("-1\n");
	}
}
