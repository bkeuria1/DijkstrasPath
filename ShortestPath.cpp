#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int findMinVertex(vector<int>distances, vector<bool>visited){
	int minVertex = 0;
	int minDistance = INT_MAX;
	for (int i = 0; i< distances.size() ; i++){
		if(!visited[i] && distances[i] < minDistance){
			minVertex = i;
			minDistance = distances[i];
		}
	}
	return minVertex;

}

void shortestPath  (vector<vector<int>> graph, int src){
	
	//initialize distance to infinity

	int num_nodes = graph.size();
	cout<<num_nodes<<endl;
	vector<int> distances(graph.size(),INT_MAX);
	vector<bool> visited(graph.size(),false);
	
	distances[src] = 0;
	
	//go through every node in the graph
	for (int i = 0; i<num_nodes;i++){
		//get the current min vertex
		int min = findMinVertex(distances,visited);
		cout<<min<<endl;
		//mark the min vertex as visited
		visited[min] = true;
		//relax each edge:

		for(int to = 0; to<num_nodes;to++){
			if(!visited[to] && distances[min] != INT_MAX && graph[min][to]!=0 && distances[min]+ graph[min][to] < distances[to]){
				distances[to] = distances[min] +graph[min][to];
				cout<<"Min distance so far from "<<src<<" to "<<to<<" is " <<distances[to]<<endl;
			}
		}
		
	}
	for( int i =0;i<distances.size();i++){
		cout<<"The distance from "<<src << " to "<<i<<" is: "<<distances[i]<<endl;
	}
	

}

int main(){
	vector<vector<int>>graph {
		{0,3,12},
		{3,0,2},
		{12,2,0}
	};

	  vector<vector<int>>graph2{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	shortestPath(graph,0);
	shortestPath(graph2,0);
}
