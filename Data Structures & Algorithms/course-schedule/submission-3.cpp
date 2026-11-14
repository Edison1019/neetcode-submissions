class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);

        for(vector<int> v : prerequisites){
            int course = v[0];
            int pre = v[1];
            adj[pre].push_back(course);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, state))
                return false;
        }

        return true;
    }

    bool dfs(int node,  vector<vector<int>>& adj, vector<int>& state){
        if(state[node] == 1){
            return false;
        }
        if(state[node] == 2){
            return true;
        }
        state[node] = 1;
        for(int course : adj[node]){
            if(!dfs(course, adj, state))
                return false;
        }
        state[node] = 2;
        return true;
    }
};
