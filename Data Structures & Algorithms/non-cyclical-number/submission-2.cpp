class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> u;
        while(!u.count(n)){
            u.insert(n);
            n = sumOfSquares(n);
            if(n == 1)
                return true;
        }
        return false;
    }
private:
    int sumOfSquares(int n) {
        int output = 0;
        while(n){
            int digit = n%10;
            output += digit*digit;
            n /= 10;
        }

        return output;
    }
};
