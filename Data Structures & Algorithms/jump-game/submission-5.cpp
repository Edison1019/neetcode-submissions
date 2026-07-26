class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tar = nums.size()-1;

        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i] >= tar) tar = i;
        }

        return tar == 0;
    }
};
