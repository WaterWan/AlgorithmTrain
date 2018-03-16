#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
const double t0 = 5417.7530;
const double t1 = 1.0 / 273.16;
const double t2 = 273.16;
const double t3 = 0.5555;
const double t4 = 6.11; 
int main() {
	double T, D, H;
	char a1, a2;
	cout << setprecision(1);
	while(true) {
		T = -200;
		D = -200;
		H = -200;
		cin >> a1;
		if(a1 == 'E') {
			break;
		}
		if(a1 == 'T') {
			cin >> T;
		} else if(a1 == 'D') {
			cin >> D;
		} else {
			cin >> H;
		}
		cin >> a2;
		if(a2 == 'T') {
			cin >> T;
		} else if(a2 == 'D') {
			cin >> D;
		} else {
			cin >> H;
		}
		if(H < -100) {
			double e = t4 * exp(t0 * (t1 - 1.0 * (1.0 / (D + t2))));
			double h = t3 * (e - 10.0);
			H = T + h;
		} else if(T < -100) {
			double e = t4 * exp(t0 * (t1 - 1.0 * (1.0 / (D + t2))));
			double h = t3 * (e - 10.0);
			T = H - h;
		} else {
			double h = H - T;
			double e = h / t3 + 10;
			double temp = e / t4;
			double temp1 = log(temp);
			double temp2 = temp1 / t0;
			double temp3 = t1 - temp2;
			double temp4 = 1.0 / temp3;
			D = temp4 - t2;
		}
		printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);
	}
	return 0;
}
