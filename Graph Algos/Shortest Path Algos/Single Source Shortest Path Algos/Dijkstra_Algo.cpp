// Dijkstra's algorithm with MIN-priority queue (It is a slight modification of BFS traversal).

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<pair<int, int>>>&, vector<int>&, int);

int main() {
	int V;
	cout<< "For Un-Directed Graph::" << endl;
	cout<< "Enter Number of Vertices: ";
	cin>> V;

	vector<vector<pair<int, int>>> graph(V);
	int E;
	cout<< "Enter Number of Edges: ";
	cin>> E;

	for(int e=0; e<E; ++e) {
		int u, w, v;
		cout<< "Edge (u, w, v) = ";
		cin>> u >> w >> v;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}
	
	vector<int> dist(graph.size(), 1e9);
	bfs(graph, dist, 0);

	cout<< "\nShortest distance:" << endl;
	for(int i=1; i<V; ++i) {
		cout<< 0 << " -> " << i << " = " << dist[i] << endl;
	}

	return 0;
}

void bfs(vector<vector<pair<int, int>>>& g, vector<int>& dist, int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min_pq({dist, v}) will sort by distance
	pq.push({0, start});

	while(!pq.empty()) {
		auto top = pq.top();
		pq.pop();

		for(auto& av: g[top.second]) {
			if(av.first + top.first < dist[av.second]) {
				dist[av.second] = av.first + top.first;
				pq.push({dist[av.second], av.second});
			}
		}
	}
}
