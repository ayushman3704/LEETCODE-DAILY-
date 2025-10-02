class Solution { // this approach: t.c O(n)  s.c O(n) (without using division operation)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int left[n]; // left array to store product of left sides element of index i
        int right[n]; // right array to store product of right sides elements of index i

        left[0] = 1; 
        right[n-1] = 1;

        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }

        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }

        vector<int> res(n);

        for(int i = 0; i < n; i++){
            res[i] = left[i] * right[i];
        }

        return res;
    }
};