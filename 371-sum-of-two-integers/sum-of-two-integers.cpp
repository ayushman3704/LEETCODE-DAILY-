class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0){
            // sum without carry
            int sum = a ^ b;

            // carry bits, shifted left
            int carry = (a & b) << 1;

            // prepare for next iteration
            a = sum;
            b = carry;
        }
        return a;
    }
};