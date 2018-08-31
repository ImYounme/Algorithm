#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ans = 987654321;
int city[51][51];
bool visited[14];

vector<pair<int, int>> chicken;
vector<pair<int, int>> person;

int cal() {
	int cmp = 0;

	for (int i = 0; i < person.size(); i++)
	{
		int dist = 987654321;
		for (int j = 0; j < chicken.size(); j++)
		{
			if (visited[j])
			{
				int px = person[i].first, py = person[i].second;
				int samx = chicken[j].first, samy = chicken[j].second;
				int d = abs(px - samx) + abs(py - samy);
				dist = min(dist, d);
			}
		}
		cmp += dist;
	}

	return cmp;
}

void go(int cur_num, int cur_cnt)
{
	if (cur_num > chicken.size()) return;
	if (cur_cnt == M) 	// M개의 치킨집이 정해지면 종료
	{
		int cmp = cal();
		ans = min(ans, cmp);

		return;
	}

	// 현재 치킨집을 사용할 경우
	visited[cur_num] = true;
	go(cur_num + 1, cur_cnt + 1);
	// 사용하지 않는 경우
	visited[cur_num] = false;
	go(cur_num + 1, cur_cnt);
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				person.push_back(make_pair(i, j));
			else if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	go(0, 0);
	cout << ans << "\n";

	return 0;
}