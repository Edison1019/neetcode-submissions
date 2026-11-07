class Solution {
public:
    int dir[4][2] ={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    set<pair<int, int>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int x, int y, int idx){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()){
            return false;
        }
        if(board[x][y] != word[idx]){
            return false;
        }
        if(visited.count({x, y})){
            return false;
        }
        if(idx == word.size() - 1){
            return true;
        }
        visited.insert({x, y});
        for(int i=0; i<4; i++){
            if(dfs(board, word, x + dir[i][0], y + dir[i][1], idx + 1)){
                return true;
            }
        }
        visited.erase({x, y});

        return false;
    }
};
