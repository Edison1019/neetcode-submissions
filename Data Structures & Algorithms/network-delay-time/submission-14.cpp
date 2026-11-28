class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> umap;
        for(vector<int>& t : times){
            umap[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        unordered_set<int> visited;
        int res = 0;

        while(!minHeap.empty()){
            int src1 = minHeap.top().second;
            int cost1 = minHeap.top().first;
            minHeap.pop();
            if(visited.count(src1)){
                continue;
            }
            visited.insert(src1);
            res = cost1;
            for(auto& p : umap[src1]){
                int src2 = p.first;
                int cost2 = p.second;
                if(!visited.count(src2)){
                    minHeap.push({res + cost2, src2});
                }
                
            }
        }

        return visited.size() == n ? res : -1;
    }
};
