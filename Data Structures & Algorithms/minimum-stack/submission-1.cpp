class MinStack {
public:
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        
    }
    
    void pop() {
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        for(int i=res.size()-1; i>=0; i--){
            s.push(res[i]);
        }
        sort(res.begin(), res.end());

        return res[0];
    }
};
