class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> v = intervals[0];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= v[1]){
                v[1] = max(intervals[i][1], v[1]);
            }
            else{
                res.push_back(v);// 沒有 overlap 就把剛才的區間放進答案
                v = intervals[i];
            }
        }

        res.push_back(v);// 最後一個 v
        return res;

    }
};
