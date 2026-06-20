class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target, int k){
        int m = l + (r-l)/2;
        long long res = 0;
        for(int i=0; i<nums.size(); i++){
            res += (nums[i] + k - 1) / k;
        }
        if(res > target)
            return binary_search(m+1, r, nums, target, k+1);
        else
            return k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        return binary_search(0, piles.size()-1, piles, h, 1);
    }
};
