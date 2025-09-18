class Solution { // using binary search.
                // Pattern: Search for Boundaries (First/Last Occurrence)
public:
    int leftMost(vector<int>& nums, int target, int n){
        int l = 0;
        int r = n-1;

        int left_most = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                left_most = mid; // it may be possible answer

                r = mid - 1; // further search in left to find left most index of the target
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return left_most;
    }

    int rightMost(vector<int>& nums, int target, int n){
        int l = 0;
        int r = n-1;

        int right_most = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                right_most = mid; 

                l = mid + 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return right_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int left_most = leftMost(nums, target, n);
        int right_most = rightMost(nums, target, n);

        return{left_most, right_most};
    }
};