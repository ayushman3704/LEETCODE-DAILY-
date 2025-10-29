class Solution { 
public:
    bool isBitSet(int n){

        return (n & (n+1)) == 0; // to check that n is set.
    }
    int smallestNumber(int n) {
        
        int res = n;
        while(!isBitSet(res)){
            res++;
        }
        return res;
    }
};