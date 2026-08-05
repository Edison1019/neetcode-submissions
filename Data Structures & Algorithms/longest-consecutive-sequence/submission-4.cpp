class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return 1;

        set<int> s;
        for(int num : nums) s.insert(num);
        int start = *s.begin();
        s.erase(s.begin());
        int result = 1, cnt = 1;

        while(!s.empty()){
            int current = *s.begin();
            if(current - start == 1){
                cnt++;
                result = max(result, cnt);
            }
            else{
                result = max(result, cnt);
                cnt = 1;
            }
            start = current;
            s.erase(s.begin());
        }

        return result;
    }
};
