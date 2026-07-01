class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subsets;
        dfs(nums, 0, target, 0, subsets);

        return res;
    }
    void dfs(vector<int>& nums, int i, int target, int sum, vector<int>& subsets){
        if(i >= nums.size()){
            return;
        }
        if(sum == target){
            res.push_back(subsets);
            return;
        }
        if(sum > target){
            return;
        }

        sum += nums[i];
        subsets.push_back(nums[i]);

        dfs(nums, i, target, sum, subsets);

        subsets.pop_back();
        sum -= nums[i];

        dfs(nums, i+1, target, sum, subsets);


    }
};
