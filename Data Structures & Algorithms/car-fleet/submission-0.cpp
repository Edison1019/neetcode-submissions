class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v;
        int res = 0;

        for(int i=0; i<position.size(); i++){
            v.push_back({position[i], (double)(target - position[i]) / speed[i]});
        } 
        sort(v.rbegin(), v.rend());

        stack<double> s;
        double max;

        for(int i=0; i<v.size(); i++){
            if(v[i].second > max){
                res++;
                max = v[i].second;
            }
        }

        return res;

    }
};
