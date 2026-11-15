class Solution {
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);

        for(vector<int>& v : prerequisites){
            adj[v[1]].push_back(v[0]);
        } 
        for(int i=0; i<adj.size(); i++){
            if(!dfs(i, state, adj)){
                return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
    bool dfs(int node, vector<int>& state, vector<vector<int>>& adj){
        if(state[node] == 1){
            return false;
        }
        if(state[node] == 2){
            return true;
        }
        state[node] = 1;
        for(int course : adj[node]){
            if(!dfs(course, state, adj)){
                return false;
            }
        }
        state[node] = 2;
        res.push_back(node);
        return true;
    }
};
