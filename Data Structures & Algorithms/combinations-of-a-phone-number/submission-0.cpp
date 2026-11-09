class Solution {
public:
    unordered_map<char, string> umap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;

    vector<string> letterCombinations(string digits) {
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string digits, int idx, string path){
        if(digits == "") return;
        if(idx == digits.size()){
            res.push_back(path);
            return;
        }
        char c = digits[idx];
        for(char ch : umap[c]){
            path.push_back(ch);
            dfs(digits, idx + 1, path);
            path.pop_back();
        }
    }
};
