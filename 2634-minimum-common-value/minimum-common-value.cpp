class Solution {
public:

    int binarySearch(vector<int> & nums2, int target){

        int n = nums2.size();

        int low = 0;
        int high = n-1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(nums2[mid] < target){
                low = mid + 1;
            }else if(nums2[mid] == target){

                return nums2[mid];
            }else{

                high = mid - 1;
            }
        }

        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int res = -1;        

        for(int i = 0; i < nums1.size(); i++){
            res = binarySearch(nums2, nums1[i]);

            if(res != -1)
            return res;
        }

        return res;
    }
};