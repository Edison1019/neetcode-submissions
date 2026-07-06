class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsets;
        dfs(nums, 0, subsets);

        return res;
    }
    void dfs(vector<int>&nums, int i, vector<int>& subsets){
        if(i == nums.size()){
            res.push_back(subsets);
            return;
        }

        dfs(nums, i+1, subsets);

        subsets.push_back(nums[i]);

        dfs(nums, i+1, subsets);

        subsets.pop_back();// 哪層加的就由哪層還回去
    }
};
