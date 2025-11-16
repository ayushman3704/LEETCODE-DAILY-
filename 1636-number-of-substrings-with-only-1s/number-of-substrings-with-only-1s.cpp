class Solution { // Approach - 1. Using simple formula (n * (n+1)/2) that calculate the number of subarray.
public:
    const int M = 1e9 + 7;
    int numSub(string s) {
        int n = s.length();

        long long count = 0;
        long long res = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                count++;
            }else{
                res = (res + count*(count+1)/2) % M;
                count = 0;
            }
        }
        // adding the last group of 1s to result.
        res = (res + count*(count+1)/2) % M;

        return (int)res;
    }
};