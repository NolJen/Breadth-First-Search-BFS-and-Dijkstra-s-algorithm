#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

//Task 1: Uniform Travel Time with BFS

//Assume the travel time between any two directly connected cities is uniform (1 hour), employ the BFS algorithm to calculate the minimum time required for a traveler to reach city `N-1` from city `0`.

//Objective: Implement the BFS algorithm to determine the shortest path in terms of the number of cities traversed. 


//define colors for BFS as taken from lecture on 11/30
#define WHITE 0
#define GRAY 1
#define BLACK 2

void bfs(int **graph, size_t num_cities, int start) {
	int color[num_cities], dist[num_cities], pred[num_cities];

	//initialize all vertices
	for (size_t i = 0; i < num_cities; i++) {
		color[i] = WHITE;	//undiscovered
		dist[i] = -1;		//distance from s
		pred[i] = -1;		//predecessor or parent
	}

	//initialize the start vertex
	color[start] = GRAY;	//frontier
	dist[start] = 0;
	pred[start] = -1;

	//create and enqueue start vertex
	Queue *queue = createQueue(num_cities);
	enqueue(queue, start);

	while (!isEmpty(queue)) {
		int u = dequeue(queue);

		//go through all adjacent vertices
		//grey nodes are frontier nodes to be explored
		for (size_t v = 0; v < num_cities; v++) {
			if (graph[u][v] != 0 && color[v] == WHITE) {
				color[v] = GRAY;	//add to frontier
				dist[v] = dist[u] + 1;
				pred[v] = u;
				enqueue(queue, v);
			}
		}
		
		color[u] = BLACK;	//done with u
	}

	//free the queue
	freeQueue(queue);

	//print the shortest distance to city N-1
	if (dist[num_cities - 1] != -1) {
		printf("%d\n", dist[num_cities - 1]);
	}
}
