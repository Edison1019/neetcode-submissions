class KthLargest {
public:
    int target;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        target = k;
        v = nums;    
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.rbegin(), v.rend());

        return v[target-1];
    }   
};
