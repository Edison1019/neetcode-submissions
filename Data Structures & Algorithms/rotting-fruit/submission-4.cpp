class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        int res = 0;
        int fresh = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        while(fresh > 0 && !q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];
                    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()
                    || grid[r][c] != 1){
                        continue;
                    }
                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }

            }
            res++;
        }

        if(fresh > 0) return -1;
        
        return res;
    }
};
