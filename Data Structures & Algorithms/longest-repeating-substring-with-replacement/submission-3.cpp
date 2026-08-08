class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> set;
        for(char c : s) set.insert(c);

        for(char c : set){
            int l = 0, cnt = 0;
            for(int r=l; r<s.size(); r++){
                if(s[r] == c) cnt++;

                if((r-l+1) - cnt > k){
                    if(s[l] == c) cnt--;
                    l++;
                }
                res = max(res, r-l+1);
            }

        }
        return res;
        
    }
};
