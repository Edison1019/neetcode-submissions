class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0;
    vector<int> result;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    result.push_back(res);
                    res = 0;
                }
            }
        }
        if(result.size() == 0) return 0;
        sort(result.rbegin(), result.rend());
        return result[0];
    }

    void dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0) return;
        if(r >= grid.size() || c >= grid[0].size()) return;
        if(grid[r][c] == 0) return;

        grid[r][c] = 0;
        res++;
        for(int i=0; i<4; i++){
            dfs(grid, r + dir[i][0], c + dir[i][1]);
        }
    }
};
