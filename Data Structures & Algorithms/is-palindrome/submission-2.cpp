class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        string s2 = "";
        for(char c : s){
            if(isalnum(c)){
                s1 += tolower(c);
            }
        }
        for(int i=s1.length()-1; i>=0; i--){
            s2 += s1[i];
        }

        return s1 == s2;
    }
};
