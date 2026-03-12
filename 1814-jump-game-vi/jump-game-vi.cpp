class Solution { // using sliding window + priority queue (lazy deletion).
    // this problem is based on leetcode- "Sliding Window Maximum"
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
    
    // Max-Heap banayenge: Pair <Score_so_far, Index>
    priority_queue<pair<int, int>> pq;
    
    // Step 1: Shuruwati index ka score PQ mein daalo
    // Pehle patthar par khade hain, toh wahan ka points mil gaya
    pq.push({nums[0], 0});
    
    int current_score = nums[0];
    
    // Step 2: Index 1 se end tak jump karna shuru karein
    for (int i = 1; i < n; i++) {
        
        // --- LAZY DELETION (Aalsi Watchman) ---
        // Agar PQ ka top element hamari range (i - K) se bahar ja chuka hai,
        // (yaani wo patthar itna peeche chhoot gaya hai ki wahan se yahan kood hi nahi sakte)
        // toh us expired score ko PQ se hata do.
        while (pq.top().second < i - k) {
            pq.pop();
        }
        
        // --- SCORE CALCULATION ---
        // PQ ke top par ab jo bacha hai, wo pichle K valid steps ka Maximum score hai.
        // Naya score = (Is patthar ke points) + (Pichle best kood ka score)
        current_score = nums[i] + pq.top().first;
        
        // Is naye score ko PQ mein daal do, taaki aage wale iska use kar sakein
        pq.push({current_score, i});
    }
    
    // Aakhri patthar tak pahunchte-pahunchte jo score bana, wahi answer hai
    return current_score;
    }
};