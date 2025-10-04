class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        unordered_map<int, int> mp;

        for(int i : nums1){
            mp[i]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(mp.find(nums2[i]) != mp.end()){
                res.push_back(nums2[i]);

                mp.erase(nums2[i]);
            }
        }
        return res;
    }
};