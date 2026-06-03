class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        reverse(digits.begin(), digits.end());
        int i = 0;
        while(carry){
            if(i < digits.size()){
                if(digits[i] == 9){
                    digits[i] = 0;
                }
                else{
                    digits[i] += 1;
                    carry = false;
                }
            }
            else{
                digits.push_back(1);
                carry = false;
            }
            i++;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }

};
