class Solution { // using prefix and sufix sum.  PATTERN - MONOTONIC STACK
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int res = 0;

        vector<int> left(n); // store maximum element in the left of the height[i].
        left[0] = height[0];

        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], height[i]);
        }

        vector<int> right(n); // store maximum element in the right of the height[i]
        right[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            res += max({min(left[i], right[i]) - height[i], 0});
        }

        return res;
    }
};

// The water that can be stored at each position is determined by the height of the shorter of the two boundaries (left and right), minus the height of the current bar.