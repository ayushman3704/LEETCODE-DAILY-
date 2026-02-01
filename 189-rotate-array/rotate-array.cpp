class Solution { // Optimal Approach- Using Reversal Algorithm
public:
    // fun to reverse the array
    void reverse(vector<int>& nums, int l, int r){

        while(l < r){
            swap(nums[l], nums[r]);

            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        reverse(nums, 0, n-1); // 1. reverse entire array
        reverse(nums, 0, k-1); // 2. reverse first k elements
        reverse(nums, k, n-1); // 3. reverse remaining n-k elements
    }
};