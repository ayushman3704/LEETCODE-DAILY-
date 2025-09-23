class Solution { // using sliding window. APPROACH - 2
public:
    int slidingWindow(vector<int> &nums, int k){
        int n = nums.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int i_badda = 0;
        int res = 0;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                mp.erase(nums[i]);

                i++;

                i_badda = i;
            }
            while(mp[nums[i]] > 1){ // shrink window size to get minimum sized window of exactly k distinct integer
                mp[nums[i]]--;
                i++;
            }
            
            if(mp.size() == k){
                res += (1 + i - i_badda); // i - i_badda, no. of extra window. +1 for minimum sized window 
            }
            j++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return slidingWindow(nums, k);
    }
};