class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for(int num : nums){
            if(sum < 0) sum = 0;
            sum += num;
            res = max(res, sum);// 擁有最大和的 subarray
        }

        return res;
    }
};
