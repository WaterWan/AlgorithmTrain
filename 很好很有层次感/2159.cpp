#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 30;
int a[maxn]; 
int b[maxn]; 

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if(s1.length() != s2.length()) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < s1.length(); i++) {
		a[s1[i] - 'A']++;
		b[s2[i] - 'A']++;
	}
	sort(a, a + maxn);
	sort(b, b + maxn);
	bool ok = true;
	for(int i = 0; i < maxn; i++) {
		if(a[i] != b[i]) {
			ok = false;
			break;
		}
	}
	if(ok) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl; 
	}
	return 0;
}
