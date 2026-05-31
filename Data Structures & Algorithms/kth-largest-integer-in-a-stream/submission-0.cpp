class KthLargest {
public:
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
    }
    
    int add(int val) {
        nums.push_back(val);
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};
