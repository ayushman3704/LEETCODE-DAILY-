class Solution { // Pattern - Hashing / Frequency | Hint: Count and check x+1
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int res = 0;

        for(int &num : nums){
            mp[num]++;
        }

        for(auto &num : nums){
            int mini = num;
            int maxi = num + 1;

            if(mp.count(maxi)){
                res = max(res, mp[mini] + mp[maxi]);
            }
        }

        return res;
    }
};