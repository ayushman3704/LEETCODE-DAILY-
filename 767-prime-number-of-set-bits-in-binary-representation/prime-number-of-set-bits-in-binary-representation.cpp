class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        // All prime numbers possible for set-bit counts (≤ 20)
        unordered_set<int> primeSet = {
            2, 3, 5, 7, 11, 13, 17, 19
        }; 
        
        int ans = 0;

        for (int x = left; x <= right; x++) {
            int cnt = 0;
            int num = x;

            // Count set bits using Brian Kernighan's algorithm
            while (num > 0) {
                num = num & (num - 1);
                cnt++;
            }

            // Check if count is prime
            if (primeSet.count(cnt)) {
                ans++;
            }
        }

        return ans;
    }
};