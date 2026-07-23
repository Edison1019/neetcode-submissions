class Solution {
public: 
    int uniquePaths(int m, int n) {
        // vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, dp);

    }

    int dfs(int r, int c, int m, int n, vector<vector<int>>& dp){
        if(r >= m || c >= n) return 0;
        // if(grid[r][c] == 1) return;
        if(r == m - 1 && c == n - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c]; 

        // grid[r][c] = 1;
        return dp[r][c] = dfs(r, c + 1, m, n, dp) + dfs(r + 1, c, m, n, dp);
    }
};
