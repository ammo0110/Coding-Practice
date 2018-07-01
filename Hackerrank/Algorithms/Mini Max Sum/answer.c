#include<stdio.h>

int main() {
	int i, arr[5], min, max;
	long sum5, minsum, maxsum;
	min = ~(1 << 31);
	max = 0;
	sum5 = 0;
	for(i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum5 += (long)arr[i];
		min = min < arr[i] ? min : arr[i];
		max = max > arr[i] ? max : arr[i];
	}
	minsum = sum5 - (long)max;
	maxsum = sum5 - (long)min;
	printf("%ld %ld\n", minsum, maxsum);
	return 0;
}
