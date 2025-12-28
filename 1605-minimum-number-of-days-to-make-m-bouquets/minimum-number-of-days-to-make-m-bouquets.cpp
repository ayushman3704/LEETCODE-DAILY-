// Pattern - "BSOA → Time / Day / Distance Based Feasibility"

class Solution {
public:

    int isPossible(vector<int>& bloomDay, int mid, int k){
        int consecutive_count = 0;
        int bouq_count = 0;

        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consecutive_count++;
            }else{
                consecutive_count = 0;
            }
            if(consecutive_count == k){
                bouq_count++;
                consecutive_count = 0;
            }
        }
        return bouq_count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int result = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(bloomDay, mid, k) >= m){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }
};