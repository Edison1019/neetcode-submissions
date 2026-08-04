class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, cnt = 0;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                cnt++;
            else
                product *= nums[i];
        }

        if(cnt > 1) return vector<int>(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(cnt)
                res.push_back((nums[i] == 0) ? product : 0);
            else
                res.push_back(product / nums[i]);
        }

        return res;
    }
};
