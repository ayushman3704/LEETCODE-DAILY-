class Solution { // using binary search. it is same as "search in rotated sorted array I". just skip the duplicates from left and right
public:
    // function to find smallest element's index in mountained or rotated array.
    int findPivot(vector<int> &nums, int n){
        int l = 0;
        int r = n-1;

        while(l < r){
            while(l < r && nums[l] == nums[l + 1]){ // skip duplicates from left
                l++;
            }
            while(l < r && nums[r] == nums[r-1]){ // skip duplicates from right
                r--;
            }

            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r])
            l = mid + 1;

            else
            r = mid;
        }
        return r;
    }

    // this is standared binary search
    bool binarySearch(int l, int r, vector<int> &nums, int target){

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                return true;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, n);

        if(binarySearch(0, pivot - 1, nums, target))
        return true;

        return binarySearch(pivot, n-1, nums, target); // search target in right sorted array
    }
};