class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;

        while(i >= 0){ // traverse from right to left
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            // else when we encounter digit 9 then make that index 0 and forward carry to left digit
            digits[i] = 0;
            i--;
        }

        digits.insert(begin(digits), 1); // this is the case where all digits elements are 9 then insert 1 at the begining of the resultant array
        return digits;
    }
};