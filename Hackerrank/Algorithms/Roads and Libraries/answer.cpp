#include<stdio.h>
#include<vector>

using namespace std;

class Graph {
	int V;	//No. of vertices

	//Pointer to an array containing adjacency lists
	vector<int> *adj;

	long DFSUtil(int s, int croad, bool *visited);
public:
	Graph(int V);	//Constructor
	void addEdge(int v, int w);
	long connectedComponents(int clib, int croad);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new vector<int>[V];
}

//Method to add an undirected edge
void Graph::addEdge(int v, int w) {
	adj[v-1].push_back(w-1);
	adj[w-1].push_back(v-1);
}

long Graph::DFSUtil(int s, int croad, bool *visited) {
	long ans = 0;
	visited[s] = true;
	for(vector<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
		if(visited[*it] == false) {
			ans += croad;
			ans += DFSUtil(*it, croad, visited);
		}
	}
	return ans;
}

long Graph::connectedComponents(int clib, int croad) {
	long ans = 0;
	bool *visited = new bool[this->V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}
	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			long roadcost = DFSUtil(i, croad, visited);
			ans += roadcost;
			ans += clib;
		}
	}
	return ans;
}

int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int n, m, clib, croad;
		scanf("%d %d %d %d", &n, &m, &clib, &croad);
		Graph g(n);
		for(int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			g.addEdge(u, v);
		}
		long ans = 0;
		if(clib > croad) {
			ans = g.connectedComponents(clib, croad);
		}
		else {
			ans = n * (long)clib;
		}
		printf("%ld\n", ans);
	}
	return 0;
}
