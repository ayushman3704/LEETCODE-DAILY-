class Solution { // Pattern- "BSOA" same as leetcode 1482.
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
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i < weights.size(); i++){
            high += weights[i];
        }

        int res = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(weights, mid, days)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};