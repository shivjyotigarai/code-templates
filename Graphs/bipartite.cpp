//https://codeforces.com/contest/1093/problem/D
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int modular_expo(int a, int b)
{
	if (b == 0)return 1;
	int result = modular_expo(a, b / 2) % mod;
	result = (result * result) % mod;
	if (b % 2 == 1)result = (result * a) % mod ;
	return result % mod;

}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n + 1);
	set<int> nodes_set;
	int ans = 1;
	int color[n + 1];
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= n; ++i)
		nodes_set.insert(i);
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i : nodes_set)
	{
		if (color[i] != -1)
			continue;
		int color1 = 0;
		int color2 = 0;
		color[i] = 1;
		color1++;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (int v : adj[node])
			{
				if (color[v] != -1)
				{
					if (color[v] == color[node])
					{
						cout << 0 << endl;
						return;
					}
					else
						continue;
				}
				color[v] = 3 - color[node];
				if (color[v] == 1)
					color1++;
				else
					color2++;
				q.push(v);
			}

		}
		
		if (color2 == 0)
		{
			ans *= modular_expo(3, 1) % mod;
			ans = ans % mod;
		}
		else
			ans *= ((modular_expo(2 , color1) * modular_expo(1, color2)) % mod + (modular_expo(1 , color1) * modular_expo(2, color2)) + mod) % mod;

	}
	ans = (ans + mod) % mod;
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//seive();
	int tc = 1;
	cin >> tc;
	while (tc--)
	{
		solve();
	}

}