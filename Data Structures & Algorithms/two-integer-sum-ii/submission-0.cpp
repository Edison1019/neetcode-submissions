class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        for(int i=0; i<numbers.size()-1; i++){
            int tar = target - numbers[i];
            for(int j=i+1; j<numbers.size(); j++){
                if(numbers[j] == tar){
                    v.push_back(i+1);
                    v.push_back(j+1);
                }
            }
        }
        return v;
    }
};
