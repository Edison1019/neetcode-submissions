class Solution {
public:
    int binarysearch(vector<int>& nums, int tar, int l, int r){
        while(l <= r){
            int mid = (l+r) / 2;
            if(nums[mid] == tar) return mid;
            if(nums[mid] > tar) r = mid - 1;
            if(nums[mid] < tar) l = mid + 1; 
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l < r){
            int mid = (l+r) / 2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        int pivot = l;
        int res = binarysearch(nums, target, 0, pivot-1);

        if(res != -1) return res;

        return binarysearch(nums, target, pivot, nums.size()-1);
    }
};
