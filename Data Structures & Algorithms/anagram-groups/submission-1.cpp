class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> u;
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];// 將排序前的字串存起來
            sort(s.begin(), s.end());
            u[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto& pair : u){
            res.push_back(pair.second);
        }

        return res;
    }
};
