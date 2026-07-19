class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for(int money : nums){
            int cur = max(prev1, money + prev2);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
