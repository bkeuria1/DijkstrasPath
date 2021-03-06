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
	//get the number of nodes in the graph
	int num_nodes = graph.size();
	vector<int> distances(num_nodes,INT_MAX);
	vector<bool> visited(num_nodes, false);
	
	distances[src] = 0;
	string pathSoFar = "";	
	//go through every node in the graph
	for (int i = 0; i<num_nodes;i++){
		//get the current min vertex
		int min = findMinVertex(distances,visited);
		pathSoFar.append(to_string(min));
		cout<<"The path so far is "<<pathSoFar<<endl;
		//mark the min vertex as visited
		visited[min] = true;
		//relax each edge:

		for(int to = 0; to<num_nodes;to++){
			if(!visited[to] && distances[min] != INT_MAX && graph[min][to]!=0 && distances[min]+ graph[min][to] < distances[to]){
				distances[to] = distances[min] +graph[min][to];
			
			}
		}
		
	}
	//print out the final distances
	for( int i =0;i<distances.size();i++){
		cout<<"The distance from "<<src << " to "<<i<<" is: "<<distances[i]<<endl;
	}
	

}

int main(){
	vector<vector<int>>graphA {
		{0,2,1,5,0,0}, //u
		{2,0,2,3,0,0}, //v
		{1,2,0,3,1,0},//x
		{5,3,3,0,1,5},//w
		{0,0,1,1,0,2},//y
		{0,0,0,5,2,0} //z
	};

	vector<vector<int>>graphB{
		{0,6,8,3,6,0,0,0}, //x
		{6,0,12,8,0,7,0}, //y
		{8,12,0,0,0,0,0}, //z
		{3,8,0,0,4,4,3}, //v
		{6,0,0,4,0,0,3}, //w
		{0,7,0,4,0,0,2},//t
		{0,0,0,3,3,2,0} //u
	};

	  vector<vector<int>>graphC{ 
		  	{0,9,8,5,0,0 }, //u
                        {9,0,1,6,0,0 }, //v
                        {8,1,0,5,2,0 }, //x
                        {0,6,5,0,6,6 }, //w
                        {0,0,2,6,0,4 }, //y
                        {0,0,0,0,6,4,0 }//z
	  };
	cout<<"Part A solution : \n"<<endl; 
	shortestPath(graphA,0); //from u
	cout<<"\n";
	cout<<"Part B solution: \n"<<endl;
	shortestPath(graphB,0); //from x
	cout<<"\n";
	cout<<"Part C solution :\n"<<endl;
	shortestPath(graphC,0); //from u
}
