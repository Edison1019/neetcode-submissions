class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if(!dfs(0, 0, visited, adj)){
            return false;
        }

        for(bool v : visited){
            if(!v){
                return false;
            }
        }

        return true;

    }

    bool dfs(int node, int parent, vector<bool>& visited, 
             vector<vector<int>>& adj)
    {
        if(visited[node]){
            return false;
        }

        visited[node] = true;

        for(int next : adj[node]){
            if(next == parent){
                continue;
            }
            if(!dfs(next, node, visited, adj)){
                return false;
            }
        }

        return true;

    }
};
