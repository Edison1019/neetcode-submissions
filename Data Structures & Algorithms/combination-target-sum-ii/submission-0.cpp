class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subsets;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0, subsets);

        return res;
    }

    void dfs(vector<int>& nums, int i, int target, int sum, vector<int>& subsets){
        if(target == sum){
            res.push_back(subsets);
            return;
        }
        if(i >= nums.size()) return;
        if(sum > target) return;
        if(sum + nums[i] > target) return;

        sum += nums[i];
        subsets.push_back(nums[i]);
        
        dfs(nums, i+1, target, sum, subsets);

        subsets.pop_back();
        sum -= nums[i];

        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        dfs(nums, i+1, target, sum, subsets);

        
    }

};
