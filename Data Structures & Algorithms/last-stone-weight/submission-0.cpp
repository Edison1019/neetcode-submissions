class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(), stones.end());
            int x = stones[stones.size() - 1];
            int y = stones[stones.size() - 2];
            if(x == y){
                stones.pop_back();
                stones.pop_back();
            }
            if(x > y)
            {
                stones.pop_back();
                stones.pop_back();
                stones.push_back(x-y);
            }
        }
        if(stones.size() == 0)
            return 0;
        else
            return stones[0];
    }

};
