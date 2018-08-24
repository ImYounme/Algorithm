#include <iostream>
#include<cstdio>
using namespace std;
int MIN = 1000000000;
int MAX = -1000000000;
int n;
int numarr[100] = {};
int p, s, m, d;

void go(int cnt,int pl, int su, int ma, int di,int value) {
	if (cnt == n) {
		if (value >= MAX)
			MAX = value;
		if (value <= MIN)
			MIN = value;
		return;
	}
	
	if (pl < p) go(cnt + 1, pl + 1, su, ma, di, value + numarr[cnt]);
	if (su < s) go(cnt + 1, pl, su + 1, ma, di, value - numarr[cnt]);
	if (ma < m) go(cnt + 1, pl, su, ma + 1, di, value * numarr[cnt]);
	if (di < d) go(cnt + 1, pl, su, ma, di + 1, value / numarr[cnt]);
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numarr[i]);
	}
	scanf("%d %d %d %d", &p ,&s, &m, &d);

	go(1, 0,0,0,0, numarr[0]);
	printf("%d\n%d\n", MAX, MIN);

	return 0;
}