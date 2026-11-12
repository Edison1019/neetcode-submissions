class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        for(char c : tasks){
            umap[c]++;
        }
        priority_queue<int> maxheap;
        for(auto& [task, freq] : umap){
            maxheap.push(freq);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!maxheap.empty() || !q.empty()){
            time++;
            if(maxheap.empty()){
                time = q.front().second;
            }
            else{
                int cnt = maxheap.top() - 1;
                maxheap.pop();
                if(cnt > 0){
                    q.push({cnt, time + n});
                }
            }

            if(q.front().second == time){
                maxheap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
