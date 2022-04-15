// Prims algorithm with MIN-priority queue.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> getMST(vector<vector<pair<int, int>>>&, int, int);

int main() {
	int V, E;
	cout<< "For Un-Directed Graph::" << endl;
	cout<< "(Vertices, Edges): ";
	cin>> V >> E;

	vector<vector<pair<int, int>>> Graph(V);
	
	for(int e=0; e<E; ++e) {
		int u, w, v;
		cout<< "Edge (u, w, v) = ";
		cin>> u >> w >> v;
		Graph[u].push_back({w, v});
		Graph[v].push_back({w, u});
	}

	vector<vector<pair<int, int>>> result = getMST(Graph, 0, V);

	cout<< "\nMinimum Spanning Tree::" << endl;
	for(int i=0; i<V; ++i) {
		for(auto& av: result[i]) {
			cout<< "(u, w, v) = " << "(" << i << ", " << av.first << ", " << av.second << ")" << endl;
		}
	}
	
	return 0;
}

vector<vector<pair<int, int>>> getMST(vector<vector<pair<int, int>>>& Graph, int start, int V) {
	vector<vector<pair<int, int>>> res(V);
	vector<int> parent(V, -1), key(V, 1e9);
	vector<bool> inMst(V, false);

	key[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
	minpq.push({0, start});

	while(!minpq.empty()) {
		auto v = minpq.top();
		minpq.pop();

		if(parent[v.second] != -1 && inMst[v.second] == false) 
			res[v.second].push_back({v.first, parent[v.second]});
		inMst[v.second] = true;

		for(auto& av: Graph[v.second]) {
			if(inMst[av.second] == false && key[av.second] > av.first) {
				parent[av.second] = v.second;
				key[av.second] = av.first;
				minpq.push(av);
			}
		}
	}
	return res;
}
