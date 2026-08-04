class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, cnt = 0;
        vector<int> res;

        for(int num : nums){
            if(num != 0)
                product *= num;
            else
                cnt++;
        }

        if(cnt > 1) return vector<int>(nums.size(), 0);

        for(int i=0; i<nums.size(); i++){
            if(cnt){
                if(nums[i] == 0) 
                    res.push_back(product);
                else
                    res.push_back(0);
            }
            else{
                res.push_back(product / nums[i]);
            }

        }


        return res;

    }
};
