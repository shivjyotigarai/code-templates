#include<bits/stdc++.h>
using namespace std;
vector<int> adj[101];
vector<int> adj_r[101];
bool visited[101];
stack<int> s;
int components=0;
void reverseG(int nodes)
{
    for(int i=0;i<nodes;++i)
    {
        for(auto it=adj[i].begin();it!=adj[i].end();++it)
        {
            adj_r[*it].push_back(i);
        }
    }
}
void DFS1(int src)
{
    visited[src]=true;
    for(auto it=adj[src].begin();it!=adj[src].end();++it)
    {
        if(visited[*it]==false)
        DFS1(*it);
    }
    s.push(src);

}
void DFS2(int src)
{
    cout<<src<<" ";
    visited[src]= true;
    for(auto it=adj_r[src].begin();it!=adj_r[src].end();++it)
    {
        if(visited[*it]==false)
        DFS2(*it);
    }
}
void printSCC(int n)
{
    for(int i=0;i<n;++i)
    visited[i]=false;
    for(int i=0;i<n;++i)
    {
        if(visited[i]==false)
        {
            DFS1(i);;
        }
    }
    reverseG(n);
    for(int i=0;i<n;++i)
    visited[i]=false;
    while(!(s.empty()))
    {
        int v= s.top();
        s.pop();
        if(visited[v]==false)
        {
            DFS2(v);
            components++;
            cout<<endl;
        }

    }
    cout<<"Total Components = "<<components<<endl;

    
}
int32_t main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    printSCC(n);
    components=0;
    for(int i=0;i<101;++i)
    {
        adj[i].clear();
        adj_r[i].clear();
    }
    memset(visited,0,sizeof(visited));

}