#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>>&, int);

int main() {
	int V;
	cout<< "For Un-Directed Graph::" << endl;
	cout<< "Enter Number of Vertices: ";
	cin>> V;

	vector<vector<int>> graph(V, vector<int>(V, 0));
	int E;
	cout<< "Enter Number of Edges: ";
	cin>> E;

	for(int e=0; e<E; ++e) {
		int u, v;
		cout<< "Edge (u, v) = ";
		cin>> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	bfs(graph, 0);

	return 0;
}

void bfs(vector<vector<int>>& g, int start) {
	vector<bool> visited(g.size(), false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()) {
		int v = q.front();
		cout<< v << " ";
		q.pop();

		for(int i=0; i<g.size(); ++i) {
			if(g[v][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
