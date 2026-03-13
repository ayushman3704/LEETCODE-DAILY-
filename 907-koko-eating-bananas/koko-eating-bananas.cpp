class Solution { // Binary search on Answer.
public:
    // This is our Predicate Function
    // It checks: "If Koko eats 'speed' bananas per hour, can she finish in 'h' hours?"
    bool canFinish(vector<int>& piles, int h, int speed) {  
        long long totalHours = 0; // Use long long to prevent integer overflow
    
        // Calculate the hours needed for each pile
        for (int i = 0; i < piles.size(); i++) {
            // Math trick to round up division: (a + b - 1) / b
            // Or you can use ceil((double)piles[i] / speed)
            totalHours += ceil((double)piles[i] / speed);
        }
    
        // If the hours it takes is less than or equal to the allowed hours 'h', it's valid
        if (totalHours <= h) {
            return true;
        } else {
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        // 1. Define the search space
        int low = 1; // Minimum possible speed
    
        // Find the maximum pile to set our upper bound
        int high = 0; 
        for(int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }
    
        int optimalSpeed = high; // Store the best answer found so far
    
        // 2. Binary Search Loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // Find the middle speed to guess
        
            // 3. Test the guess using our helper function
            if (canFinish(piles, h, mid) == true) {
                // If she CAN finish at this speed, it's a potential answer.
                // But we want the MINIMUM speed. So we record this, and try slower speeds.
                optimalSpeed = mid;
                high = mid - 1; // Discard the right half (faster speeds)
            } else {
                // If she CANNOT finish at this speed, it is too slow.
                // We must force her to eat faster.
                low = mid + 1; // Discard the left half (slower speeds)
            }
        }
    
        return optimalSpeed;
    }
};