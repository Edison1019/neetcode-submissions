class Solution {
public:
    set<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, {});
        vector<vector<int>> result;
        
        for(auto& subsets : res){
            result.push_back(subsets);
        }

        return result;
    }

    void backtrack(vector<int>&nums, int idx, vector<int> subset){
        if(idx == nums.size()){
            res.insert(subset);
            return;
        }
        subset.push_back(nums[idx]);
        backtrack(nums, idx + 1, subset);
        subset.pop_back();
        backtrack(nums, idx + 1, subset);
    }
    
};
