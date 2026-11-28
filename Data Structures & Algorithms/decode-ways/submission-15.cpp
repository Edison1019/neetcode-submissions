class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(0, s, memo);
    }
    int dfs(int i, string& s, vector<int>& memo){
        if(i > s.size()){
            return 0;
        }
        if(i == s.size()){
            return 1;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int way = 0;
        if(s[i] != '0'){
            way += dfs(i + 1, s, memo);
        }
        if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
            way += dfs(i + 2, s, memo); 
        }
        memo[i] = way;
        return way;
    }
};
