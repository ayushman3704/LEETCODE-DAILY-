class Solution { // using map. 
public:

    int reverseNum(int num){

        int rev = 0;

        while(num > 0){

            rev = rev * 10 + (num % 10);

            num /= 10;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        
        unordered_map<int, int> mp;
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        // Check if current number exists as reverse of previous
        if (mp.find(nums[i]) != mp.end()) {
            ans = min(ans, i - mp[nums[i]]);
        }

        int rev = reverseNum(nums[i]);
        // Store reversed value
        mp[rev] = i;
    }

    return (ans == INT_MAX) ? -1 : ans;
    }
};