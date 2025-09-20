class Solution { // using binary search. this problem is combination of "find peak index in mountained array" and "standared binary search"
public:
    // function to find smallest element's index in mountained or rotated array.
    int findPivot(vector<int> &nums, int n){
        int l = 0;
        int r = n-1;

        while(l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r])
            l = mid + 1;

            else
            r = mid;
        }
        return r;
    }

    // this is standared binary search
    int binarySearch(int l, int r, vector<int> &nums, int target){
        int ind = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                ind = mid;
                break;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ind;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, n);

        int ind = binarySearch(0, pivot - 1, nums, target); // search target in left sorted array

        if(ind != -1)
        return ind;

        ind = binarySearch(pivot, n-1, nums, target); // search target in right sorted array

        return ind;
    }
};