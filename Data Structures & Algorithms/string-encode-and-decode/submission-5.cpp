class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for(int i=0; i<strs.size(); i++){
            // if(i != strs.size()-1)
                res += strs[i] + '.';
            // else
            //     res += strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string res;
        for(int i=0; i<s.size(); i++){
            if(s[i] != '.'){
                res += s[i];
            }
            else{
                result.push_back(res);
                res = "";
            }

        }

        return result;
    }
};
