// Tarjan's Algorithm to find articulation points (applicable only for un-Directed Graphs)
/*  
Referred solution From here :: https://www.youtube.com/watch?v=qNVNoZJFp_g
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> findAP(vector<vector<int>>&, int);
void dfs(vector<vector<int>>&, int, vector<int>&, vector<int>&, vector<int>&, vector<int>&, vector<bool>&, int&);

int main() {
	int V, E;
	cout<< "(Vertices, Edges) = ";
	cin>> V >> E;

	vector<vector<int>> Graph(V);

	for(int e=0; e<E; ++e) {
		int u, v;
		cout<< "(u, v) = ";
		cin>> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector<int> artPoints = findAP(Graph, V);

	if(artPoints.size() == 0) cout<< "\nNo Articulation Points." << endl;
	else {
		cout<< "\nArticulation Points are = ";
		for(int& ap: artPoints) cout<< ap << " ";
		cout<< endl;
	}

	return 0;
}

// functions used in main()
void dfs(vector<vector<int>>& Graph, int v, vector<int>& res, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& visited, int& time) {
	visited[v] = true;
	disc[v] = ++time;
	low[v] = disc[v];
	int child = 0;

	for(int& av: Graph[v]) {
		if(!visited[av]) {
			child++;
			parent[av] = v;
			dfs(Graph, av, res, disc, low, parent, visited, time);
			low[v] = min(low[v], low[av]);

			// for root element
			if(parent[v] == -1 && child > 1)
				res.push_back(v);
			if(parent[v] != -1 && low[av] >= disc[v])
				res.push_back(v);
		}
		else if(av != parent[v]){ // back edge
			low[v] = min(low[v], disc[av]);
		}
	}
}

vector<int> findAP(vector<vector<int>>& Graph, int V) {
	vector<int> res, disc(V, 0), low(V, 0), parent(V, -1);
	vector<bool> visited(V, false);
	int time = 0, start = 0;

	dfs(Graph, start, res, disc, low, parent, visited, time);

	return res;
}
