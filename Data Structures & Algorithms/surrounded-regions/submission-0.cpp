class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int j=0; j<n; j++){
            dfs(0, j, board);
            dfs(m - 1, j, board);
        }
        for(int i=1; i<m-1; i++){
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()){
            return;
        }
        if(board[x][y] == 'X'){
            return;
        }
        if(board[x][y] == '*'){
            return;
        }
        if(board[x][y] == 'O'){
            board[x][y] = '*';
        }
        for(int i=0; i<4; i++){
            dfs(x + dir[i][0], y + dir[i][1], board);
        }
    }
};
