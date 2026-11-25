class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                       greater<pair<int, int>>> minheap;
        vector<bool> visited(points.size(), false);

        int res = 0;
        minheap.push({0, 0});
        while(!minheap.empty()){
            int cost = minheap.top().first;
            int id = minheap.top().second;

            minheap.pop();
            if (visited[id]){
                continue;
            }
            visited[id] = true;
            res += cost;

            for(int i=0; i<points.size(); i++){
                if(visited[i]){
                    continue;
                }
                int dist = abs(points[id][0] - points[i][0]) + 
                           abs(points[id][1] - points[i][1]);

                minheap.push({dist, i});
            }
        }

        return res;

    }
};
