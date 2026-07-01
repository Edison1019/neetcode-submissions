class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subsets;
        dfs(nums, 0, target, 0, subsets);

        return res;
    }
void dfs(vector<int>& nums, int i, int target, int sum, vector<int>& subsets){
    // 1. 終點線防護
    if(i >= nums.size()) return;

    // 2. 動作一：強迫拿當前的數字 (你的原創思路)
    sum += nums[i];
    subsets.push_back(nums[i]);

    // 3. 判斷剛才那個動作的結果
    if(sum == target){
        res.push_back(subsets); 
        // 達標了！存起來。但不能 return，因為還要探索不拿這個數字的平行時空。
    }
    else if(sum < target){
        // 只有在還沒爆掉的情況下，才有資格「繼續拿同一個數字」
        dfs(nums, i, target, sum, subsets);
    }

    // 4. 時光倒流 (不管剛才是達標、爆掉、還是沒爆，都要把剛剛拿的數字吐出來)
    subsets.pop_back();
    sum -= nums[i];

    // 5. 動作二：不拿當前數字，走向下一個
    dfs(nums, i+1, target, sum, subsets);
}
};
