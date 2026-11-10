class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res;
        priority_queue<int> q;
        for(int n : nums){
            q.push(n);
        }
        while(q.size() > 0 && k > 0){
            res = q.top(); 
            q.pop();
            k--;
        }

        return res;
    }
};
