class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();

        int i = 0;
        while(i < n-1){
            i += (bits[i] == 1) ? 2 : 1; // if bits[i] == 1 hai to i ko 2 se increment krenge else 1 se increment krenge
        }

        return i == n-1; 
    }
};