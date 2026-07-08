class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subsets;
        vector<bool> pick(nums.size(), false);
        dfs(nums, pick, subsets);

        return res;
    }
    void dfs(vector<int>& nums, vector<bool>& pick, vector<int>& subsets){
        if(subsets.size() == nums.size()){
            res.push_back(subsets);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!pick[i]){
                subsets.push_back(nums[i]);
                pick[i] = true;
                dfs(nums, pick, subsets);
                subsets.pop_back();
                pick[i] = false;
            }
        }
    }
};
