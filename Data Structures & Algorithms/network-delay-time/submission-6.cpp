class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> umap;
        for(auto& time : times){
            umap[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        unordered_set<int> visited;
        int t = 0;
        while(!minHeap.empty()){
            int dis1 = minHeap.top().first;
            int node1 = minHeap.top().second;
            minHeap.pop();

            if(visited.count(node1)) continue;
            visited.insert(node1);
            t = dis1;
            for(auto& pair : umap[node1]){
                int node2 = pair.first, dis2 = pair.second;
                if(!visited.count(node2)){
                    minHeap.push({dis1 + dis2, node2});
                }
            }


        }

        if(visited.size() == n) return t;

        return -1;
    }
};
