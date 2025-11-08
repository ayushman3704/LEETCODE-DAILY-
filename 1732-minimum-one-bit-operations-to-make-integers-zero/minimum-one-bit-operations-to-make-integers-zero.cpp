class Solution { // watch solution to learn formula 
public:
    int minimumOneBitOperations(int n) {
        
        if(n == 0)
        return 0;

        vector<long long> F(31, 0); // vector that store minimum number of operations to transform n into 0. 

        F[0] = 1; // minimum number of operations to transform 1 into 0.
        for(int i = 1; i <= 30; i++){
            F[i] = 2*F[i-1] + 1; // formula to calculate minimum number of operations to transform n into 0.
        }

        int sign = 1;
        int result = 0;

        for(int i = 30; i >= 0; i--){ // traverse vector left to right

            int ithBit = ((1<<i) & n); // find ith bit (i.e., ith bit is 0 ot 1)

            if(ithBit == 0)
            continue;

            if(sign > 0)
            result += F[i];
            else
            result -= F[i];

            sign = sign*(-1); // alter the sign
        }
        return result;
    }
};