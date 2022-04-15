// Bell man Ford algorithm (DP) Works only for directed edges.

#include<iostream>
#include<vector>

using namespace std;

struct node {
	int u, w, v;

	node(int& U, int& W, int& V) {
		u = U;
		w = W;
		v = V;
	}
};

int main() {
	int V, E;
	cout<< "(Vertices, Edges): ";
	cin>> V >> E;

	vector<node> Edges;

	// collect all edges
	for(int i=0; i<E; ++i) {
		int u, v, w;
		cout<< "(u, w, v) = ";
		cin>> u >> w >> v;
		Edges.push_back(node(u, w, v));
	}

	vector<int> dist(V, 1e9);
	dist[0] = 0; // start vertex
	
	for(int i=V-1; i>0; --i) {
		for(auto edge: Edges) {
			if(dist[edge.v] > dist[edge.u] + edge.w) 
				dist[edge.v] = dist[edge.u] + edge.w;
		}
	}

	// check for Negative Weight cycle
	for(auto edge: Edges) {
		if(dist[edge.v] > dist[edge.u] + edge.w) {
			cout<< "\nNegative Weight Cycle Exists!. So Cannot find shortest path...";
			return 0;
		}
	}

	// display shortest path
	cout<< "\nShortest path Details::" << endl;
	for(int i=1; i<V; ++i) {
		cout<< 0 << " -> " << i << " = " << dist[i] << endl;
	}

	return 0;
}
