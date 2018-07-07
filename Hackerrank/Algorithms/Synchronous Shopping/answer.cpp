#include<stdio.h>
#include<vector>
#include<algorithm> // For min and max
#include<utility>	// For pair
#include<set>

#define MAX 1005

using namespace std;

int fishmask[MAX];
vector<pair<int, int> > adj[MAX];
int dist[MAX][1024];

void dijkstra_mod(pair<int, int> s) {
	set<pair<int, pair<int, int> > > pq; // Going to use this set as a priority queue
	pq.insert(make_pair(0, s));

	while(!pq.empty()) {
		/* The minimum priority element will be at top */
		int u = pq.begin()->second.first; // The node
		int m = pq.begin()->second.second;	// The mask representing the type of fishes u has
		int d = pq.begin()->first;

		pq.erase(pq.begin());	// Remove this node from priority queue

		/* Let's relax the neighbours of u */
		vector<pair<int, int> >::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = it->first;	// The neighbour node
			int w = it->second;	// The weight of the road connecting u and v
			int vmask = fishmask[v];	// The type of fishes v has
			if(d + w < dist[v][m|vmask]) {
				/* Erase the edge if it is present in the priority queue */
				pair<int, pair<int, int> > mp = make_pair(dist[v][m|vmask], make_pair(v, m|vmask));
				pq.erase(mp);
				/* Update this and add it to priority queue */
				dist[v][m|vmask] = d + w;
				pair<int, pair<int, int> > p = make_pair(dist[v][m|vmask], make_pair(v, m|vmask));
				pq.insert(p);
			}
		}
	}
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; i++) {
		int T;
		scanf("%d", &T);
		for(int j = 0; j < T; j++) {
			int x;
			scanf("%d", &x);
			fishmask[i] |= (1 << (x-1));
		}
	}
	for(int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(make_pair(v-1, w));
		adj[v-1].push_back(make_pair(u-1, w));
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < (1 << K); j++) {
			dist[i][j] = ~(1 << 31);
		}
	}
	/* The source is at 0 node */
	dist[0][fishmask[0]] = 0;
	dijkstra_mod(make_pair(0, fishmask[0]));

	/* Brute Forcing the partition between two synchronous travellers */
	int ans = ~(1 << 31);
	for(int i = 0; i < (1 << K); i++) {
		for(int j = 0; j < (1 << K); j++) {
			if((i | j) == ((1 << K) -1))	{
				ans = min(ans, max(dist[N-1][i], dist[N-1][j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
