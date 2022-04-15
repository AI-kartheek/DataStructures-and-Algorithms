// Kahns algorithm (Modified BFS Algorithm). It works under rule called "append indegree=0 First"

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> getTopologicalSort(vector<vector<int>>&, int);

int main() {
	int V, E;
	cout<< "For Directed Graph::" << endl;
	// cout<< "(Vertices, Edges): ";
	// cin>> V >> E;.
	V = 6;
	E = 5;

	vector<vector<int>> Graph(V);
	
	// for(int e=0; e<E; ++e) {
	// 	int u, v;
	// 	cout<< "Edge (u, v) = ";
	// 	cin>> u >> v;
	// 	Graph[u].push_back(v);
	// }

	Graph[0].push_back(2);
	Graph[1].push_back(0);
	Graph[3].push_back(1);
	Graph[4].push_back(1);
	Graph[5].push_back(2);

	vector<int> result = getTopologicalSort(Graph, V);
	
	// check for cycle
	if(result.size() != V) cout<< "\nTopological Sort is not possible due to cycle in a Graph." << endl;
	else {
		cout<< "\nTopological Sort = ";
		for(int& v: result) cout<< v << " ";
		cout<< endl;
	}

	return 0;
}

vector<int> getTopologicalSort(vector<vector<int>>& Graph, int V) {
	queue<int> q;
	vector<int> res, indegree(V, 0);

	// find indegree of all vertices
	for(int i=0; i<V; ++i) {
		for(int& av: Graph[i]) {
			indegree[av]++;
		}
	}

	for(int i=0; i<V; ++i) {
		if(indegree[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int v = q.front();
		res.push_back(v);
		q.pop();

		for(int& av: Graph[v]) {
			indegree[av]--;
			if(indegree[av] == 0) q.push(av);
		}
	}

	return res;
}
