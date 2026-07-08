class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subsets;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, target, subsets);

        return res;
    }
    void dfs(vector<int>& nums, int i, int sum, int target, vector<int>& subsets){
        if(sum == target){
            res.push_back(subsets);
            return;
        }
        if(i >= nums.size()) return;
        if(sum > target) return;
        if(nums[i] + sum > target) return;

        sum += nums[i];
        subsets.push_back(nums[i]);

        dfs(nums, i, sum, target, subsets);

        subsets.pop_back();
        sum -= nums[i];

        dfs(nums, i+1, sum, target, subsets);
    }
};
