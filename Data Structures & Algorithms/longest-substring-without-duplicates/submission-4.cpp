class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        for(int i=0; i<s.size(); i++){
            unordered_set<char> u;
            int r = i;
            int res = 0;
            while(r < s.size()){
                if(u.count(s[r]) == 0){
                    u.insert(s[r]);
                    res++;
                }
                else{
                    break;
                }
                r++;
            }
            result = max(result, res);
        }

        return result;
    }
};
