class Solution { // using sliding window standard template. call slinding window twice once for k and once for k - 1
public:
    int slidingWindow(vector<int> &nums, int k){
        int n = nums.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        int count = 0;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                mp.erase(nums[i]);

                i++;
            }
            count += j - i + 1; // no. of total subarray of size less than or equal to k, ending at j

            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // by subtracting total no. of subarrays which has less than or equal to k-1 distict integer from k distict integer subarrays will give the total no. of subarrays which has exactly k distict integers
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};