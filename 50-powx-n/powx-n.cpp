class Solution {   // recursion (multi tree recursion).
public:
    double power(double x, long long n) {
    // BASE CASE
    if(n == 0)
        return 1.0;

    // RECURSIVE CALL (STATE REDUCTION)
    double half = power(x, n / 2);

    // COMBINE RESULTS (CHOICE RESOLUTION)
    if(n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

    double myPow(double x, int n) {
        
        long long nn = n;
        if (nn < 0){
            x = 1/x;
            nn = -nn;
        }

        return power(x, nn);
    }
};