#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
vector<int> tree;
int sum(int v, int node_low, int node_high, int query_low, int query_high)
{
	if (query_low <= node_low && node_high <= query_high)
		return tree[v];
	if (query_low > node_high || query_high < node_low)
		return 0;// out of range
	int last_in_left = (node_low + node_high) / 2;
	return sum(2 * v, node_low, last_in_left, query_low, query_high) + sum(2 * v + 1, last_in_left + 1, node_high, query_low, query_high);

}
int find_min(int v, int node_low, int node_high, int query_low, int query_high)
{
	if (query_low <= node_low && node_high <= query_high)
		return tree[v];
	if (query_low > node_high || query_high < node_low)
		return INT_MAX;// out of range
	int last_in_left = (node_low + node_high) / 2;
	return min(find_min(2 * v, node_low, last_in_left, query_low, query_high), find_min(2 * v + 1, last_in_left + 1, node_high, query_low, query_high));
}
int find_max(int v, int node_low, int node_high, int query_low, int query_high)
{
	if (query_low <= node_low && node_high <= query_high)
		return tree[v];
	if (query_low > node_high || query_high < node_low)
		return INT_MIN;// out of range
	int last_in_left = (node_low + node_high) / 2;
	return max(find_max(2 * v, node_low, last_in_left, query_low, query_high), find_max(2 * v + 1, last_in_left + 1, node_high, query_low, query_high));
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
    
    //UPDATE according to your operation :- sum in this example
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}
int32_t main()
{
	int n, q; // number of elements in the array
	cin >> n >> q;
	vector<int> arr(n);//Array on which the segment tree is build.(0 based indexing)
	for (int i = 0; i < n; ++i) cin >> arr[i];
	while (__builtin_popcount(n) != 1)
	{
		arr.push_back(0);
		n++;
	}
	tree.resize(2 * n);
	//BUILDING(important)
	for (int i = 0; i < n; ++i)
		tree[n + i] = arr[i];

	for (int i = n - 1; i >= 1; --i)
		tree[i] = tree[2 * i] + tree[2 * i + 1]; // any associative property such as XOR, max, min etc

	while (q--)
	{
		int query;
		cin >> query;
		if (query == 1)
		{
            //FINDING SUM IN THE RANGE [low,high] in the array arr
			int low, high;
			cin >> low >> high;
			// if low and high are 1 based
			--low;
			--high;
			cout << sum(1, 0, n - 1, low, high) << endl;
		}
		else
		{
            // UPDATING POSITION WITH A GIVEN VALUE in the array arr
			int position, value;
			cin >> position >> value;
			//if position is 1 based
			--position;
			update(1, 0, n - 1, position, value);
		}

	}



	return 0;
}