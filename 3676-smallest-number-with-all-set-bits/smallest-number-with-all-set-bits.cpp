class Solution { 
public:
    int smallestNumber(int n) {
        
        int res = 1;

        while(res < n){
            res = 2*res + 1; // next set bit number
        }

        return res;
    }
};