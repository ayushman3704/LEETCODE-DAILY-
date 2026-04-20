class Solution { // this is nothing but implement lower bound. Lower bound is the index.
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();

        int l = 0; 
        int r = n-1;

        while(l < r){

            int mid = l + (r-l)/2;

            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        if(l < n && nums[l] < target)
        l++;

        return l;
    }
};