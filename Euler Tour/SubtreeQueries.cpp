//https://cses.fi/problemset/task/1137/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 10;
using namespace std;
vector<int> subord(MAXN);
vector<vector<int> >adj(MAXN);
vector<int> st(MAXN);
vector<int> en(MAXN);
vector<int> pos(MAXN);
vector<int> tree;
int timer = 0;
int sum(int v, int node_low, int node_high, int query_low, int query_high)
{
	if (query_low <= node_low && node_high <= query_high)
		return tree[v];
 
	if (query_low > node_high || query_high < node_low)
		return 0;// out of range
 
	int last_in_left = (node_low + node_high) / 2;
	return sum(2 * v, node_low, last_in_left, query_low, query_high) + sum(2 * v + 1, last_in_left + 1, node_high, query_low, query_high);
 
}
void update(int v, int node_low, int node_high, int pos, int val)
{
	if ((node_low == node_high) && (pos == node_low))
	{
		tree[v] = val;
		return;
	}
	if (pos > node_high || pos < node_low)
		return;
 
	int last_in_left = (node_low + node_high) / 2;
 
	if (pos <= last_in_left)
		update(2 * v, node_low, last_in_left, pos, val);
	else
		update(2 * v + 1, last_in_left + 1, node_high, pos, val);
 
	tree[v] = tree[2 * v] + tree[2 * v + 1];
 
}
void dfs(int src, int par)
{
	pos[timer] = src;
	st[src] = timer++;
	for (auto v : adj[src])
	{
		if (v == par)
			continue;
		dfs(v, src);
	}
	en[src] = timer - 1;
}
void solve()
{
	int n, q;
	cin >> n >> q;
	int value[n];
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> value[i];
	for (int i = 1; i <= n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	
	for (int i = 0; i < n; ++i)
	{
		arr[i] = value[pos[i]];
	}
	while (__builtin_popcount(n) != 1)
	{
		arr.push_back(0);
		n++;
	}
	// for (auto x : arr)
	// 	cout << x << " ";
	// cout << endl;
	tree.resize(2 * n);
	for (int i = 0; i < n; ++i)
		tree[n + i] = arr[i];
	for (int i = n - 1; i >= 1; --i)
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	while (q--)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
			int node;
			cin >> node;
			--node;
			int position = st[node];
			int x;
			cin >> x;
			update(1, 0, n - 1, position, x);
		}
		else if (query == 2)
		{
			int node;
			cin >> node;
			--node;
			int position = st[node];
			int query_low = position;
			int query_high = position + (en[node] - st[node]);
			cout << sum(1, 0, n - 1, query_low, query_high) << endl;
 
		}
 
	}
 
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
	{
		solve();
	}
 
}