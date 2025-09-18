class Solution { // using binary search. this solution is same as "Peak Index in Mountain Array"
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < r){
            int mid = l + (r - l)/2;

            if(nums[mid] < nums[mid + 1])
            l = mid + 1; // consider only after mid elements i.e., from mid + 1
            else
            r = mid; // consider before mid + 1 element i.e., from mid
        }
        return r;
    }
};