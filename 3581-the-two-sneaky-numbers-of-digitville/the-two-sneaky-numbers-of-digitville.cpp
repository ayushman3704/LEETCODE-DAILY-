class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;

        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            if(it.second == 2){
                res.push_back(it.first);

                // if(res.size() == 2)
                // break;
            }
        }
        return res;
    }
};