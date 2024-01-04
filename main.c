#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bfs.h"
#include "dijkstra.h"

//helper funciton to read the graph from the input file
int **readGraph(char *filename, int *num_cities, int *num_links) {
	FILE *file = fopen(filename, "r");
	if (!file) {
		perror("Error opening file");
		return NULL;
	}	

	fscanf(file, "%d", num_cities);
	fscanf(file, "%d", num_links);

	// Allocate memory for the adjacency matrix
	int **graph = (int**)malloc(*num_cities * sizeof(int*));
	for (int i = 0; i < *num_cities; i++) {
		graph[i] = (int*)calloc(*num_cities, sizeof(int));
	}

	// Read the links
	for (int i = 0; i < *num_links; i++) {
		int city1, city2, time;
		fscanf(file, "%d,%d,%d", &city1, &city2, &time);
		graph[city1][city2] = time;
		graph[city2][city1] = time;
	}
	
	fclose(file);
	return graph;
}

//free the graphs memory
void freeGraph(int **graph, int num_cities) {
	for (int i = 0; i < num_cities; i++) {
		free(graph[i]);
	}
	free(graph);
}

int main() {
	char filename[100];		//store the file name
	scanf("%s", filename);		//read the file from input
	
	int num_cities, num_links;
	int **graph = readGraph(filename, &num_cities, &num_links);
	if (!graph) return 1;

	int command;
	while (1) {

		scanf("%d", &command);
		switch (command) {
			case 0: {
				//'0' instructs the program to preform the BFS (Breath-First Search) algorithm
				//Task 1: Uniform Travel Time with BFS
				//Assume the travel time between any two directly connected cities is uniform (1 hour), employ the BFS algorithm to calculate the minimum time required for a traveler to reach city `N-1` from city `0`.
				//Objective: Implement the BFS algorithm to determine the shortest path in terms of the number of cities traversed. 
				bfs(graph, num_cities, 0);
				break;
				}
			case 1: {
				//'1' is a directive to run Dijkstra's algorithm
				//Task 2: Varied Travel Time with Dijkstra's Algorithm
				//Now, consider the actual travel times `w` between cities. Use Dijkstra's algorithm to compute the minimum travel time needed for a traveler to go from city `0` to city `N-1`.
				//Objective: Implement Dijkstra's algorithm to find the shortest path in terms of travel time.
				//Note: You can either use array or heap to implement Dijkstra's algorithm. 
				dijkstra(graph, num_cities, 0);
				break;
				}
			case 2: {
				//extra credit if I wanted to
				//'2'2 is a directive to run the bonus task.
				//Bonus Challenge
				//Modify your implementation to introduce a constraint: the traveler cannot pass through more than `K` cities. Notice that you should include the starting city in the count of cities visited.
				//Objective: Adapt your Dijkstra's algorithm to account for the maximum number of cities (`K`) that can be visited during the journey. 
				break;
				}
			case 3: {
				//'3' signals the program to terminate
				printf("Goodbye\n");
				return 0;
				}
		}
	}

	freeGraph(graph, num_cities);
	return 0;
}

