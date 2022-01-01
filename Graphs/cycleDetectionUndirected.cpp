#include<bits/stdc++.h>
using namespace std;
vector<int> adj[101];
bool visited[101];
bool DFS(int src,int par)
{
    visited[src]=true;
    int flag=0;
    bool check=false;
    for(auto it= adj[src].begin();it!=adj[src].end();++it)
    {
        if(*it==par)
        continue;
        if(visited[*it]) return true;
        if(visited[*it]==false)
        {
            flag=1;
            check+=(DFS(*it,src));
        }
    }
    if(flag==1)
    return check;
    return false;
}
int32_t main()
{
    int n,e;
    cin>>n>>e;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     
    }
    for(int i=0;i<n;++i)
    {
        if(!visited[i] && DFS(i,-1))
        {cout<<"Cycle Detected at "<<i<<" vertex Sub Graph"<<endl;return 0;}
    }
    cout<<"No Cycle Detected"<<endl;
    return 0;


}