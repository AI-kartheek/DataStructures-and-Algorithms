/*  Adjacency list representation using 2-D vector in main() */

// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
// 	int V, E;
// 	cout<< "(V, E) = ";
// 	cin>> V>> E;

// 	vector<vector<int>> G(V);

// 	for(int e=0; e<E; ++e) {
// 		int u, v;
// 		cout<< "(u, v) = ";
// 		cin>> u >> v;
// 		G[u].push_back(v);
// 		G[v].push_back(u);
// 	}

// 	cout<< "\nAdjacency List of Graph: " << endl;
// 	for(int v=0; v<V; ++v) {
// 		cout<< "Vertex, " << v << " -> ";
// 		for(int& e: G[v]) {
// 			cout<< e << ", ";
// 		}
// 		cout<< endl;
// 	}
// }


/*  Adjacency list representation using static array of linked list. */

// #include<iostream>
// #include<list>

// using namespace std;

// class Graph {
// 	int V, E;
// 	list<int> *G;

// public:
// 	Graph(int V, int E) {
// 		this->V = V;
// 		this->E = E;
		
// 		G = new list<int>[V];
// 	}

// 	void addEdge(bool undirected=true) {
// 		int u, v;
// 		cout<< "Edge (u, v) = ";
// 		cin>> u >> v;

// 		G[u].push_back(v);
// 		if(undirected) G[v].push_back(u);
// 	}

// 	void display() {
// 		cout<< "\nAdjacency List of Graph: " << endl;
// 		for(int v = 0; v<V; ++v) {
// 			cout<< "Vertex, " << v << " -> ";
// 			for(auto& e: G[v]) {
// 				cout<< e << ", ";
// 			}
// 			cout<< endl;
// 		}
// 	}
// };


// int main() {
// 	int V, E;
// 	cout<< "Enter Number of Vertices in a Graph: ";
// 	cin >> V;
// 	cout<< "Enter Number of Edges in a Graph: ";
// 	cin >> E;

// 	Graph g(V, E);
// 	for(int e=0; e<E; ++e) {
// 		g.addEdge();
// 	}

// 	g.display();
// }


/*  Adjacency list representation using 2-D vector in a class. */

#include<iostream>
#include<vector>

using namespace std;

class Graph {
	int V, E;
	vector<vector<int>> G;

public:
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
		
		// we can't use G.reserve(V). So we use below code.
		for(int i=0; i<V; ++i) {
			G.push_back(vector<int>());
		}
	}

	void addEdge(bool undirected=true) {
		int u, v;
		cout<< "Edge (u, v) = ";
		cin>> u >> v;

		G[u].push_back(v);
		if(undirected) G[v].push_back(u);
	}

	void display() {
		cout<< "\nAdjacency List of Graph: " << endl;
		for(int v = 0; v<V; ++v) {
			cout<< "Vertex, " << v << " -> ";
			for(auto& e: G[v]) {
				cout<< e << ", ";
			}
			cout<< endl;
		}
	}
};


int main() {
	int V, E;
	cout<< "Enter Number of Vertices in a Graph: ";
	cin >> V;
	cout<< "Enter Number of Edges in a Graph: ";
	cin >> E;

	Graph g(V, E);
	for(int e=0; e<E; ++e) {
		g.addEdge();
	}

	g.display();
}