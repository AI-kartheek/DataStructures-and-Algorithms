/*  Recursive approach which used implicit stack.  */

// #include<iostream>
// #include<vector>

// using namespace std;

// void dfs(vector<vector<int>>&, vector<bool>&, int);

// int main() {
// 	int V;
// 	cout<< "For Un-Directed Graph::" << endl;
// 	cout<< "Enter Number of Vertices: ";
// 	cin>> V;

// 	vector<vector<int>> graph(V, vector<int>(V, 0));
// 	int E;
// 	cout<< "Enter Number of Edges: ";
// 	cin>> E;

// 	for(int e=0; e<E; ++e) {
// 		int u, v;
// 		cout<< "Edge (u, v) = ";
// 		cin>> u >> v;
// 		graph[u][v] = 1;
// 		graph[v][u] = 1;
// 	}

// 	vector<bool> visited(graph.size(), false);
// 	dfs(graph, visited, 0);

// 	return 0;
// }

// void dfs(vector<vector<int>>& g, vector<bool>& visited, int v) {
// 	visited[v] = true;
// 	cout<< v << " ";
	
// 	for(int i=0; i<g.size(); ++i) {
// 		if(g[v][i] == 1 && !visited[i]) {
// 			dfs(g, visited, i);
// 		}
// 	}
// }


/*  STACK based approach  */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(vector<vector<int>>&, vector<bool>&, int);

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

	vector<bool> visited(graph.size(), false);
	dfs(graph, visited, 0);

	return 0;
}

void dfs(vector<vector<int>>& g, vector<bool>& visited, int start) {
	stack<int> st;
	st.push(start);
	visited[start] = true;
	
	while(!st.empty()) {
		int v = st.top();
		visited[v] = true;
		st.pop();
		cout<< v << " ";

		for(int i=0; i<g.size(); ++i) {
			if(g[v][i] == 1 && !visited[i]) {
				visited[i] = true;
				st.push(i);
			}
		}
	}
}
