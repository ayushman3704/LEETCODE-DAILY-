class Solution { // using map
public:
    int repeatedNTimes(vector<int>& nums) {
        int N = nums.size();

        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int n = N/2;

        for(auto it : freq){
            if(it.second >= n){
                return it.first;
            }
        }
        return -1;
    }
};