class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int res = 0;
        for(int i=0; i<tokens.size(); i++){
            s.push(tokens[i]);
            if(s.top() == "+"){
                s.pop();
                int op1 = stoi(s.top());
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                res = op1 + op2;
                s.push(to_string(res));
            }
            if(s.top() == "-"){
                s.pop();
                int op1 = stoi(s.top());
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                res = op2 - op1;
                s.push(to_string(res));
            }
            if(s.top() == "*"){
                s.pop();
                int op1 = stoi(s.top());
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                res = op1 * op2;
                s.push(to_string(res));
            }
            if(s.top() == "/"){
                s.pop();
                int op1 = stoi(s.top());
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                res = op2 / op1;
                s.push(to_string(res));
            }
        }

        return stoi(s.top());
    }
};
