class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int u,vector<bool> &visited,vector<bool> &visited_curr,vector<int> adj[])
    {
        visited[u]=true;
        visited_curr[u]=true;
        bool check = false;
        for(auto v:adj[u])
        {
            if(!visited[v]) 
            check+=dfs(v,visited,visited_curr,adj);
            else if(visited_curr[v])
            return true;
        }
        visited_curr[u] = false;
        return check;

    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> visited_curr(V,false);
        for(int i=0;i<V;++i)
        {
            if(!visited[i]&& dfs(i,visited,visited_curr,adj))
            return true;
        }
        return false;
    }
};
