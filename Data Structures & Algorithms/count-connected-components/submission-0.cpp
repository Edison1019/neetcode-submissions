class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        int res = 0;
        for(vector<int> v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                dfs(i, visited, adj);
                res++;
            }
        }

        return res;
    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        for(int next : adj[node]){
            if(visited[next] == true){
                continue;
            }
            dfs(next, visited, adj);
        }

    }
};
