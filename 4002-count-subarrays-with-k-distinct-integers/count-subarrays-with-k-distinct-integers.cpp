class Solution { // Otimized approach using Slinding Window
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        
        unordered_map<int, int> freq;

        int l = 0;

        long long ans = 0;

        int extra = 0, distinct = 0, good = 0;

        for(int r = 0; r < nums.size(); r++){

            freq[nums[r]]++;

            if(freq[nums[r]] == 1)
            distinct++;

            if(freq[nums[r]] == m)
            good++;

            // too many distinct, shrink window
            while(l < r && distinct > k){

                extra = 0;

                if(freq[nums[l]] == m)
                good--;

                freq[nums[l]]--;

                if(freq[nums[l]] == 0)
                distinct--;

                l++;
            }

            // remove extra duplicates
            while(distinct == k && good == k && freq[nums[l]] > m){

                freq[nums[l]]--;

                l++;

                extra++;
            }

            if(distinct == k && good == k)
            ans += (extra + 1);
        }

        return ans;
    }
};