class Solution {
public: 
    unordered_set<int> u;
    bool isHappy(int n) {
        if(u.count(n))
            return false;
        u.insert(n);
        if(n>=1 && n<10){
            if(n == 1)
                return true;
            return isHappy(n*n);
        }   
        if(n>=10 && n<100){
            if(n == 10)
                return true;
            int x = n/10;
            int y = n - x*10;
            return isHappy(x*x + y*y);
        }
        if(n>=100 && n<1000){
            if(n == 100)
                return true;
            int x = n/100;
            int y = n - x*100;
            int z = y/10;
            int h = y - z*10;
            return isHappy(x*x + z*z + h*h);            
        }
        if(n == 1000){
            return true;
        }
    }
};
