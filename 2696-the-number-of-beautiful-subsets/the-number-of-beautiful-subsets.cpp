class Solution { // backtracking. based on count total number of subset 
public:
    int n;
    int K;
    int res;

    void solve(int ind, vector<int>& nums, unordered_map<int, int> &mp){
        if(ind >= n){
            res++;
            return;
        }

        solve(ind+1, nums, mp); // not take

        if(!mp[nums[ind] - K] && !mp[nums[ind] + K]){ // check before taking element that if element is already in map and absolute different is not equal to k
            mp[nums[ind]]++; 
            solve(ind+1, nums, mp);
            mp[nums[ind]]--; // backtrack
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        K = k;
        unordered_map<int, int> mp;

        solve(0, nums, mp);
        return res -1; // exlcuding empty subset
    }
};