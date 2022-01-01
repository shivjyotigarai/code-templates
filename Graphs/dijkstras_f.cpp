#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
vector<pair<int,int> > adj[101];
vector<bool> visited(101);
vector<int> connection(101);
void shortestPath(int src,int nodes)
{
    priority_queue< pair<int,int> , vector <pair<int,int> > , greater <pair<int,int> > > pq;
    vector<int> dist(nodes+1, INF);
    pq.push(make_pair(0, src));
	dist[src] = 0;
    while (!pq.empty())
	{  
		int u = pq.top().second;
        visited[u]=true;
		pq.pop();
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (!visited[v] && dist[v] > dist[u] + weight)
			{
                connection[v]=u;
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
    	
	cout<<"Vertex Distance from Source\n";
    for (int i = 1; i <= nodes; ++i)
		cout<<dist[i]<<" ";

}

void print_graph(int end)
{
    cout<<end<<endl;
    while(connection[end]!=-1)
    {
        cout<<connection[end]<<endl;
        end=connection[end];
    }
}

int32_t main()
{
    int n,e;// nodes and edges respectively
    cin>>n>>e;
    for(int i=0;i<e;++i)
    {
        int u,v,l;
        cin>>u>>v>>l;
        //0 based indexing
        adj[u].push_back(make_pair(v,l));
        adj[v].push_back(make_pair(u,l));
    }
    int vertex;
    cin>>vertex;
    connection[vertex]=-1;
    shortestPath(vertex,n);
    cout<<endl;
    print_graph(6);
}