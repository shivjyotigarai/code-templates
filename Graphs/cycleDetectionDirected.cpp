#include<bits/stdc++.h>
using namespace std;
vector<int> adj[101];
bool visited[101];
bool DFSvisited[101];
bool DFS(int src)
{
    visited[src]=true;
    DFSvisited[src]=true;
    for(auto it= adj[src].begin();it!=adj[src].end();++it)
    {
        if(!visited[*it]) return DFS(*it);
        else if(DFSvisited[*it]) return true;
    }
    DFSvisited[src]=false;
    return false;
}
int32_t main()
{
    int n,e;
    cin>>n>>e;
    memset(visited,0,sizeof(visited));
    memset(DFSvisited,0,sizeof(DFSvisited));
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
     
    }
    for(int i=0;i<n;++i)
    {
        if(!visited[i] && DFS(i))
        {cout<<"Cycle Detected at "<<i<<" vertex Sub Graph"<<endl;return 0;}
    }
    cout<<"No Cycle Detected"<<endl;
    return 0;
}