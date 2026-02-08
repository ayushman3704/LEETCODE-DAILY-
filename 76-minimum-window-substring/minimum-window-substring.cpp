class Solution { // sliding window + hashmap
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need, window;

        for(char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        int l = 0;
        int r = 0;
        
        int start = 0;
        int minLen = INT_MAX;
        string res = "";

        while(r < s.size()){

            window[s[r]]++;

            if(need.count(s[r]) && window[s[r]] == need[s[r]])
            formed++;

            while(l <= r && formed == required){

                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }

                char left = s[l];
                window[left]--;

                if(need.count(left) && window[left] < need[left])
                formed--;

                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);

    }
};