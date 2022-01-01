//https://codeforces.com/contest/1037/submission/136850792
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 200005;
vector<vector<int> > adj(MAXN);
int visited[MAXN];
int dist[MAXN];
int par[MAXN];
void solve()
{
	int n;
	cin >> n;
	int arr[n + 1];
	int indexOf[n + 1];
	for (int i = 1; i <= n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	par[1] = -1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		visited[node] = true;
		for (int v : adj[node])
		{
			if (!visited[v])
			{
				dist[v] = dist[node] + 1;
				par[v] = node;
				q.push(v);
			}
		}

	}
	// for (int i = 1; i <= n; ++i)
	// 	cout << par[i] << " ";
	// cout << endl;
	// for (int i = 1; i <= n; ++i)
	// 	cout << dist[i] << " ";
	// cout << endl;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	if (n == 1)
	{
		cout << "YES" << endl;
		return;
	}
	for (int i = 2; i <= n; ++i)
	{
		int node1 = arr[i - 1];
		int parent1 = par[node1];
		int distance1 = dist[node1];
		indexOf[node1] = i - 1;
		int node2 = arr[i];
		int parent2 = par[node2];
		int distance2 = dist[node2];
		indexOf[node2] = i;
		if (parent1 == -1)
		{
			if (distance1 <= distance2)
				continue;
			else
			{
				cout << "NO" << endl;
				return;
			}

		}
		else if (parent2 == -1)
		{
			cout << "NO" << endl;
			return;
		}
		if (distance1 <= distance2 && indexOf[parent1] <= indexOf[parent2])
			continue;
		else
		{
			cout << "NO" << endl;
			return;
		}

	}

	cout << "YES" << endl;


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
	// cin >> tc;
	while (tc--)
		solve();

}