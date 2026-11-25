class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for(vector<int> e : edges){
            int u = e[0];
            int v = e[1];
            vector<bool> visited(edges.size() + 1, false);
            if(dfs(u, v, visited, adj)){
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    }

    bool dfs(int node,  int target, 
             vector<bool>& visited, vector<vector<int>>& adj)
    {
        visited[node] = true;
        if(visited[target]){
            return true;
        }
        for(int next : adj[node]){
            if(visited[next]){
                continue;
            }
            if(dfs(next, target, visited, adj)){
                return true;
            }
        }

        return false;
    }
};
