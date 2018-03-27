#include <stdio.h>
#include <string.h>
const int maxn = 210;
int a[maxn];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(a, 0, sizeof a);
		int N;
		scanf("%d", &N);
		while(N--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(x % 2 == 0) {
				x /= 2;
				x--;
			} else {
				x /= 2;
			}
			if(y % 2 == 0) {
				y /= 2;
				y--;
			} else {
				y /= 2;
			}
			if(x > y) {
				int temp = y;
				y = x;
				x = temp;
			}
			for(int i = x; i <= y; i++) {
				a[i]++;
			}
		}
		int max_m = 0;
		for(int i = 0; i < maxn; i++) {
			max_m = a[i] > max_m ? a[i] : max_m;
		}
		printf("%d\n", max_m * 10);
	}
	return 0;	
}
