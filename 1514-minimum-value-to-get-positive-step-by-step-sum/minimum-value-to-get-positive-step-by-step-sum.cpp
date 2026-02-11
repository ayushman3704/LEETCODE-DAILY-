class Solution { // using prefix sum
public:
    int minStartValue(vector<int>& nums) {
        
        int prefix = 0;
        int minPrefix = 0;

        for(int x : nums){
            prefix += x;
            minPrefix = min(minPrefix, prefix);
        }

        return 1 - minPrefix;
    }
};

// Constraint-   x + prefix[i] >= 1   for all i
// From the constraint:  x >= 1 - prefix[i]   for all i
// So to satisfy all positions, x must satisfy the worst case: x >= 1 - (minimum prefix sum)

