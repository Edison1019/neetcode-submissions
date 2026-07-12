class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }

        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0) 
            return;
        if(r >= grid.size())
            return;
        if(c >= grid[0].size())
            return;
        if(grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        for(int i=0; i<4; i++){
            dfs(grid, r + dir[i][0], c + dir[i][1]);
        }
    }
};
