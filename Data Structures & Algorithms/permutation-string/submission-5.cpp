class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.length();
        sort(s1.begin(), s1.end());

        for(int i=0; i<s2.length() - len + 1; i++){
            string s = "";
            for(int j=i; j<i + len; j++){
                s += s2[j];
            }
            sort(s.begin(), s.end());
            if(s1 == s) return true;
        }

        return false;
    }
};
