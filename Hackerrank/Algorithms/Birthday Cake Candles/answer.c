#include<stdio.h>

int main() {
	long max;
	int i, N, count;
	max = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		int height;
		scanf("%d", &height);
		if(max == height) {
			count++;
		}
		else if(max < height) {
			max = height;
			count = 1;
		}
		else
			continue;
	}
	printf("%d\n", count);
	return 0;
}
