class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max;
        for(int s:stones){
            max.push(s);
        }

        while(max.size() > 1){
            int x = max.top();
            max.pop();
            int y = max.top();
            max.pop();
            if(x > y)
                max.push(x-y);
        }
        if(max.size() == 1)
            return max.top();
        else
            return 0;
    }
};
