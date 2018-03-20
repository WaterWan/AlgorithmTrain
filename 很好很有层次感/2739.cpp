#include <stdio.h>
#include <string.h>
/*
* 素数筛选，存在小于等于MAXN的素数
* prime[0] 存的是素数的个数
*/
const int MAXN = 10010;
int prime[MAXN + 1];

void getPrime() {
	memset(prime, 0, sizeof prime);
	for(int i = 2;i <= MAXN; i++) {
		if(!prime[i]) {
			prime[++prime[0]]=i;
		}
		for(int j = 1;j <= prime[0] && prime[j] <= MAXN/i; j++) {
			prime[prime[j]*i]=1;
			if(i%prime[j] == 0) {
				break;
			}
		}
	}
}



int main() {
	getPrime();
	int sum;
	while(true) {
		scanf("%d", &sum);
		if(sum == 0) {
			break;
		}
		int l = 1;
		int r = 1;
		int cnt = 0;
		int total = prime[1];
		while(prime[r] <= sum && r <= prime[0]) {
			if(total < sum) {
				r++;
				total += prime[r];
			} else if(total == sum) {
				cnt++;
				total -= prime[l];
				l++;
				r++;
				total += prime[r];
			} else {
				total -= prime[l];
				l++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
