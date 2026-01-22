class Solution { // variable size sliding window 
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> mp;
        int i = 0;

        int ans = 0;
        for(int j = 0; j < n; j++){

            mp[s[j]]++; // include 

            while(mp[s[j]] > 1){ // window is invalid, shrink window
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                mp.erase(s[i]);

                i++;
            }

            ans = max(ans, j-i+1); // window is valid, update ans
        }
        return ans;
    }
};