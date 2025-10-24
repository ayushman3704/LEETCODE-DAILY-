class Solution { // simple brute force approach
public:
    bool isBalance(int n){

        vector<int> freq(10);

        while(n > 0){ // fill freq vector to store the frequency of the digit present in the n
            int digit = n % 10;
            freq[digit]++;

            n = n/10;
        }

        for(int i = 0; i < 10; i++){ // traverse on freq vector
            if(freq[i] > 0 && freq[i] != i)
            return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        
        for(int i = n+1; i <= 1224444; i++){ // 1224444 last balenced number strictly greater than 1e6(test case limit)
            if(isBalance(i))
            return i;
        }
        return 0;
    }
};