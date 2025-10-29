class Solution { 
public:
    int smallestNumber(int n) {
        
        int bits = log2(n) + 1; // to calculate number of bits in any decimal number.

        return (1 << bits) - 1;
    }
};