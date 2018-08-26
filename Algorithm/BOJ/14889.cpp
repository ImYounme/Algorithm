#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool is_used[20];
int s[20][20];
int ans = 987654321;

void dfs(int cur, int cnt)
{
	if (cnt == n / 2) // n/2명 뽑았으면 팀 구성
	{
		vector<int> team1, team2;

		for (int i = 0; i < n; i++)
		{
			if (is_used[i]) team2.push_back(i);
			else team1.push_back(i);
		}

		// 능력치 차이 구함
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < team2.size(); i++)
		{
			for (int j = i + 1; j < team2.size(); j++) 
			{
				sum1 += s[team2[i]][team2[j]] + s[team2[j]][team2[i]];
				sum2 += s[team1[i]][team1[j]] + s[team1[j]][team1[i]];
			}
		}

		ans = min(ans, abs(sum1 - sum2));
		return;
	}

	for (int i = cur + 1; i < n; i++) 
	{
		if (is_used[i] == false)
		{
			is_used[i] = true;
			dfs(i, cnt + 1);
			is_used[i] = false;
		}
	}

}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}
	dfs(0, 0);
	cout << ans << "\n";

	return 0;
}