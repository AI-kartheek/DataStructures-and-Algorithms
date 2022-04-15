// Modified DFS Algorithm. It works under rule called "append outdegree=0 First"

/*
 Learnt cycle detection in a directed graphs here :: https://www.youtube.com/watch?v=uzVUw90ZFIg
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool findTopoSortIfNoCycle(vector<vector<int>>&, int, stack<int>&);
bool dfs(vector<vector<int>>&, int, vector<bool>&, vector<bool>&, stack<int>&);

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
	// Graph[2].push_back(1);  // this line gives cycle in the graph 

	stack<int> result;

	// returns true if there is a cycle, else return false and result variable has topological sort.
	bool cycle = findTopoSortIfNoCycle(Graph, V, result);
	
	// check for cycle
	if(cycle) cout<< "\nTopological Sort is not possible due to cycle in a Graph." << endl;
	else {
		cout<< "\nTopological Sort = ";
		while(!result.empty()) {
			cout<< result.top() << " ";
			result.pop();
		}
		cout<< endl;
	}
	
	return 0;
}

// functions used in the main()
bool dfs(vector<vector<int>>& Graph, int v, vector<bool>& visited, vector<bool>& dfsVisit, stack<int>& result) {
	visited[v] = true;
	dfsVisit[v] = true;

	for(int& av: Graph[v]) {
		if(!visited[av]) {
			if(dfs(Graph, av, visited, dfsVisit, result))
				return true;
		}
		else if(dfsVisit[av]) 
			return true;
	}

	result.push(v);
	return dfsVisit[v] = false;
}

bool findTopoSortIfNoCycle(vector<vector<int>>& Graph, int V, stack<int>& result) {
	vector<bool> visited(V, false), dfsVisit(V, false);

	for(int v=0; v<V; ++v) {
		if(!visited[v])
			if(dfs(Graph, v, visited, dfsVisit, result))
				return true;
	}

	return false;
}
