class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> res;        
        // for(int i=0; i<heights.size(); i++){
        //     for(int j=0; j<heights[0].size(); j++){
        //         dfs(i, j, heights);
        //     }
        // }
        for(int j=0; j<n; j++){
            dfs(0, j, heights, pac);
            dfs(m-1, j, heights, atl);
        }
        for(int i=0; i<m; i++){
            dfs(i, 0, heights, pac);
            dfs(i, n-1, heights, atl);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;

    }

    void dfs(int x, int y, vector<vector<int>>& heights,
            vector<vector<bool>>& visited){
        
        visited[x][y] = true;

        for(int i=0; i<4; i++){

            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size()){
                continue;
            }
            if(visited[nx][ny] == true){
                continue;
            }
            if(heights[nx][ny] >= heights[x][y]){
                dfs(nx, ny, heights, visited);
            }

        }
    }

};
