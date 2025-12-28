class Solution { // copy-paste code of leetcode- 1011. Capacity To Ship Packages Within D Days
public:
    bool isPossible(vector<int>& weights, int mid, int days){
        int day = 1;
        int currLoad = 0;

        for(int i = 0; i < weights.size(); i++){
            if(currLoad + weights[i] <= mid){
                currLoad += weights[i];
            }else{
                day++;
                currLoad = weights[i];
            }
            if(day > days)
            return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int i = 0; i < nums.size(); i++){
            high += nums[i];
        }

        int res = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, mid, k)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};