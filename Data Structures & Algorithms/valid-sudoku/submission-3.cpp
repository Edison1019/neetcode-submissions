class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++){
            unordered_set<char> set;
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                if(set.count(board[i][j])) return false;
                set.insert(board[i][j]);

            }
        }
        for(int i=0; i<9; i++){
            unordered_set<char> set;
            for(int j=0; j<9; j++){
                if(board[j][i] == '.') continue;
                if(set.count(board[j][i])) return false; 
                set.insert(board[j][i]);
            }
        }
        int r = 0, c = 0;

        while(r <= 6 && c <= 6){
            unordered_set<char> set;
            for(int i=r; i<r+3; i++){
                for(int j=c; j<c+3; j++){
                    if(board[i][j] == '.') continue;
                    if(set.count(board[i][j])) return false; 
                    set.insert(board[i][j]);         
                }
            }
            if(c == 9){
                c = 0;
                r += 3;
            }
            else{
                c += 3;
            }
        }

        return true;
    }
};
