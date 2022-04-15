// Krushkals algorithm.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int w, u, v;

	node(int U, int W, int V) {
		w = W;
		u = U;
		v = V;
	}
};

class KruskalsAlgo {
public:
	vector<int> parent, rank;
	int V, E;

	KruskalsAlgo(int V, int E) {
		this->V = V;
		this->E = E;
	}

	vector<node> getMST() {
		vector<node> Edges, res;

		// for(int e=0; e<E; ++e) {
		// 	int u, w, v;
		// 	cout<< "Edge (u, w, v) = ";
		// 	cin>> u >> w >> v;
		// 	Edges.push_back(node(u, w, v));
		// }

		Edges.push_back(node(0, 2, 5));
		Edges.push_back(node(0, 2, 1));
		Edges.push_back(node(0, 7, 3));
		Edges.push_back(node(1, 5, 5));
		Edges.push_back(node(1, 4, 3));
		Edges.push_back(node(1, 1, 2));
		Edges.push_back(node(1, 3, 4));
		Edges.push_back(node(2, 4, 5));
		Edges.push_back(node(2, 4, 4));
		Edges.push_back(node(3, 1, 4));
		Edges.push_back(node(3, 5, 6));
		Edges.push_back(node(4, 7, 6));

		// make_set and rank vector creation.
		for(int i=0; i<V; ++i) {
			parent.push_back(i);
			rank.push_back(0);
		}

		sort(Edges.begin(), Edges.end(), [](auto& x, auto& y){return x.w < y.w;});
		
		for(auto edge: Edges) {
			if(find(edge.u) != find(edge.v)) {
				res.push_back(edge);
				union_set(edge.u, edge.v);
			}
		}
		
		return res;
	}

	int find(int v) {
		if(parent[v] != v) parent[v] = find(parent[v]);

		return parent[v];
	}

	void union_set(int u, int v) {
		int rootX = find(u);
		int rootY = find(v);

		if(rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else {
			parent[rootX] = rootY;
			if(rank[rootX] == rank[rootY]) {
				rank[rootY]++;
			}
		}
	}
};


int main() {
	int V, E;
	cout<< "For Un-Directed Graph::" << endl;
	// cout<< "(Vertices, Edges): ";
	// cin>> V >> E;
	V = 7;
	E = 12;

	KruskalsAlgo krus(V, E);
	vector<node> result = krus.getMST();

	cout<< "\nMinimum Spanning Tree::" << endl;
	for(int i=0; i<result.size(); ++i) {
		cout<< "(u, w, v) = " << "(" << result[i].u << ", " << result[i].w << ", " << result[i].v << ")" << endl;
	}

	return 0;
}

