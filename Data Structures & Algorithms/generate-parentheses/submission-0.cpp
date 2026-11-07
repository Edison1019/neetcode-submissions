class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, "");
        return res;
    }

    void backtrack(int n, int left, int right, string subset){
        if(left == n && right == n){
            res.push_back(subset);
            return;
        }
        if(left < n){
            subset.push_back('(');
            backtrack(n, left + 1, right, subset);
            subset.pop_back();
        }
        if(right < left){
            subset.push_back(')');
            backtrack(n, left, right + 1, subset);
            subset.pop_back();
        }
    }
};
