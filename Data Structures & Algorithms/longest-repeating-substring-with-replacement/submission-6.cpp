class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> uset;

        for(char c : s) uset.insert(c);

        for(char c : uset){
            int l = 0, cnt = 0;
            for(int r=l; r<s.size(); r++){
                if(s[r] == c) cnt++;
                while((r-l+1) - cnt > k){
                    if(s[l] == c) cnt--;
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};
