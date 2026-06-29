class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        vector<vector<int>> res;
        for(int i=0; i<points.size(); i++){
            int dis = 0 - (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            q.push({dis, i});
        }
        while(k--){
            res.push_back(points[q.top().second]);
            q.pop();
        }

        return res;
    }
};
