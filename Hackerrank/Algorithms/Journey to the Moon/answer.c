#include<stdio.h>
#include<string.h>

#define MAX 100005
int arr[MAX];
int rank[MAX];
int count[MAX];
char visited[MAX];

void make_set(int s) {
	arr[s] = s;
	rank[s] = 1;
	count[s] = 1;
}

int find_set(int s) {
	while(arr[s] != s) {
		s = arr[s];
	}
	arr[s] = s;
	return s;
}

void link_sets(int x, int y) {
	if(rank[x] == rank[y]) {
		arr[y] = x;
		rank[x]++;
		count[x] += count[y];
	}
	else if(rank[x] > rank[y]) {
		arr[y] = x;
		count[x] += count[y];
	}
	else {
		arr[x] = y;
		count[y] += count[x];
	}
}

void merge_sets(int u, int v) {
	int x = find_set(u);
	int y = find_set(v);
	if(x != y)
		link_sets(x, y);
}

int main() {
	int i, n, p;
	long ans;
	FILE *fp = stdin;
	fscanf(fp, "%d %d", &n, &p);
	ans = (n * (long)(n-1)) / 2;
	for(i = 0; i < n; i++)
		make_set(i);
	for(i = 0; i < p; i++) {
		int u, v;
		fscanf(fp, "%d %d", &u, &v);
		merge_sets(u, v);
	}
	memset(visited, 0x00, sizeof(visited));
	for(i = 0; i < n; i++) {
		int s = find_set(i);
		if(visited[s] == 0 && count[s] > 1) {
			long t = (count[s] * (long)(count[s]-1)) / 2;
			ans -= t;
			visited[s] = 1;
		}
	}
	printf("%ld\n", ans);
	fclose(fp);
}
