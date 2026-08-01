class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> v = intervals[0]; 

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= v[1]){
                v[1] = max(intervals[i][1], v[1]);
            } 
            else {
                res.push_back(v);
                v = intervals[i];
            }
        }
        res.push_back(v);

        return res;
        
    }
};
