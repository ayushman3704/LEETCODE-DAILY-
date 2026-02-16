class Solution { // bit manipulation
public:
    int reverseBits(int n) {
        
        int res = 0;

        for(int i = 0; i < 32; i++){

            uint32_t lastBit = n&1;  // Step 1: Extract the least significant bit of n

            res = res<<1; // Step 2: Left shift result to make space for new bit

            res = res | lastBit; // Step 3: Insert extracted bit into result

            n = n>>1; // Step 4: Right shift n to process next bit
        }
        return res;
    }
};