class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> substring;
        dfs(0, s, substring);
        
        return res;
    }

    void dfs(int start, string s, vector<string> substring){
        if(start == s.size()){
            res.push_back(substring);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string part = s.substr(start, i - start + 1);
            if(isPalindrome(part)){
                substring.push_back(part);
                dfs(i + 1, s, substring);
                substring.pop_back();
            }

        }
    }  

    bool isPalindrome(string s){
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
