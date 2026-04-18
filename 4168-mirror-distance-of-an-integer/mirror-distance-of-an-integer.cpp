class Solution {
public:
    // function to reverse number.
    int reverseN(int n){ 

        int rev = 0;
        while(n > 0){

            rev = rev * 10 + (n % 10);

            n /= 10;
        }

        return rev;
    }

    int mirrorDistance(int n) {
        
        return abs(reverseN(n) - n);
    }
};