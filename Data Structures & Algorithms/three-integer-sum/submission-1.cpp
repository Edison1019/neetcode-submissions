class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        set.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        for(auto& s : set){
            res.push_back(s);
        }

        return res;
    }
};
