class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return 1;

        set<int> s;
        for(int num : nums) s.insert(num);
        int start = *s.begin();
        s.erase(s.begin());
        int result = 1, res = 1;

        while(!s.empty()){
            int current = *s.begin();
            if(current - start == 1){
                res++;
                result = max(result, res);
            }
            else{
                result = max(result, res);
                res = 1;
            }
            start = current;
            s.erase(s.begin());
        }

        return result;
    }
};
