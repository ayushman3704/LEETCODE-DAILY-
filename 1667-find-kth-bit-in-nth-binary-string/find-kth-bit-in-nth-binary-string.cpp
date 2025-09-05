class Solution { // using recurssion. this problem is similar to "kth symbol in grammar"
public:
    char findKthBit(int n, int k) {
        if(n == 1)
        return '0';

        int len = pow(2, n) - 1; // (1 << n) - 1
        int mid = len/2 + 1;

        if(k == mid)
        return '1';

        else if(k < mid){
            return findKthBit(n-1, k);
        }
        char ch = findKthBit(n-1, len - (k-1));
        return ch == '1' ? '0' : '1'; // we have to return inverted char so invert the char 
    }
};