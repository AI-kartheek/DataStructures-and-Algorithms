// floyd-warshall algorithm (DP) implemented with Adjacency Matrix for a directed Graph.

#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<int>>& Graph) {
	int V = Graph.size();
	cout<< "\nShortest path Matrix::"<< endl;
	for(int i=0; i<V; ++i) {
		for(int j=0; j<V; ++j) {
			cout<< Graph[i][j] << " ";
		}
		cout<< endl;
	}
}

int main() {
	int V, E;
	cout<< "(Vertices, Edges): ";
	cin>> V >> E;

	vector<vector<int>> Graph(V, vector<int> (V, 1e9));

	for(int i=0; i<V; ++i) Graph[i][i] = 0;

	// collect all edges
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cout<< "(u, w, v) = ";
		cin>> u >> w >> v;
		Graph[u][v] = w;
	}

	for(int k=0; k<V; ++k) {
		for(int i=0; i<V; ++i) {
			for(int j=0; j<V; ++j) 
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
		}
	}

	// display shortest path
	display(Graph);
	
	return 0;
}
