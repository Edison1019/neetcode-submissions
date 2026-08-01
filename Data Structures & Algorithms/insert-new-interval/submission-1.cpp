class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        // 把第一台車當作第一隻史萊姆
        vector<int> v = intervals[0]; 

        for(int i = 1; i < intervals.size(); i++){
            // 檢查有沒有重疊（因為已經 sort 過，intervals[i][0] 一定 >= v[0]）
            // 所以其實只要檢查：新車頭 <= 史萊姆尾巴 就可以了！
            if(intervals[i][0] <= v[1]){
                // 史萊姆吞噬合併
                v[1] = max(intervals[i][1], v[1]);
            } else {
                // 發現斷開了（沒重疊），代表這隻史萊姆吃不下了
                res.push_back(v); // 1. 把舊史萊姆封存進答案箱
                v = intervals[i]; // 2. 把這台新車當作「全新的一隻史萊姆」
            }
        }

        // 3. 迴圈結束後，別忘了把手上最後一隻史萊姆放進答案箱！
        res.push_back(v);

        return res;
        
    }
};
