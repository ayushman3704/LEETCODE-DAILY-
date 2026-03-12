class Solution { // using sliding window + priority_queue. (lazy deletion).
                // This problem is variance of leetcode- "1696. Jump Game VI"
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
    
        // DP array har index par best sum store karne ke liye
        vector<int> dp(n, 0);
    
        // Max-Heap: Pair <Best_Sum, Index>
        priority_queue<pair<int, int>> pq;
    
        // Base Case initialization
        dp[0] = nums[0];
        pq.push({dp[0], 0});
    
        int overall_max_sum = dp[0];
    
        // Loop shuru karo
        for (int i = 1; i < n; i++) {
        
            // --- LAZY DELETION (Aalsi Watchman) ---
            // Agar window size K se choti ho gayi hai index gap mein, 
            // toh use fek do.
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }
        
            // --- THE TWIST ---
            // Agar pichla best score hi humein barbaad (negative) kar raha hai,
            // toh usko lene ka koi logic nahi hai. Hum 0 le lenge (Fresh start).
            int prev_best = max(0, pq.top().first);
        
            // Naya sum calculate karo
            dp[i] = nums[i] + prev_best;
        
            // Global answer ko update karo, kyunki zaroori nahi answer aakhri element par hi mile
            overall_max_sum = max(overall_max_sum, dp[i]);
        
            // Apne current best sum aur index ko history (PQ) mein daal do
            pq.push({dp[i], i});
        }
    
        return overall_max_sum;
    }
};