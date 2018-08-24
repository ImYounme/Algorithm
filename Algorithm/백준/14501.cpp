#include <iostream>
#include<cstdio>
#include <algorithm>
#define MAX_SIZE 16

using namespace std;

int t[MAX_SIZE];
int p[MAX_SIZE];
int n;
int MAX = 0;

void go(int cur, int s) {
	if (cur == n + 1) {
		MAX = max(MAX, s);
		return;
	}

	if (cur + t[cur] <= n + 1) { // 오늘 상담함
		go(cur + t[cur], s + p[cur]);
	}
	if (cur + 1 <= n + 1) { // 오늘 상담 하지않음
		go(cur + 1, s);
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	go(1, 0);
	printf("%d\n", MAX);

	return 0;
}