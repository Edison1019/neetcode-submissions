class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> u ={
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char c : s){
            if(!u.count(c)){ //確認是左括號 or 右括號
                stack.push(c);
            }
            else{
                if(!stack.empty() && u[c] == stack.top())
                    stack.pop();
                else
                    return false;
            }            
        }
        return stack.empty();
    }
};
