class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> res(temperatures.size(), 0);

        s.push({0, temperatures[0]});

        for(int i=1; i<temperatures.size(); i++){
                while(!s.empty() && temperatures[i] > s.top().second){
                    res[s.top().first] = i - s.top().first;
                    s.pop();
                }
            s.push({i, temperatures[i]});
        }

        return res;
    }
};
