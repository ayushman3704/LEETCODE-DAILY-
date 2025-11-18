class Solution { // Approach - 2
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();

        int count = 0;
        for(int i = n-2; i >= 0; i--){
            if(bits[i] == 1){
                count++;
            }else{
                break;
            }
        }

        return count % 2 == 0; 
    }
};