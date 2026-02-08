class Solution { // sliding window + hashmap. same as leetcode- 76
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> need, window;

        for(char &c : p) need[c]++;

        int left = 0;
        int right = 0;

        int required = need.size();
        int formed = 0;

        vector<int> res;

        while(right < s.size()){

            window[s[right]]++;

            if(need.count(s[right]) && window[s[right]] == need[s[right]])
            formed++;

            if(right - left + 1 > p.size()){

                char l = s[left];

                if(need.count(l) && window[l] == need[l])
                formed--;

                window[l]--;
                left++;
            }
            if(required == formed)
            res.push_back(left);

            right++;
        }

        return res;
    }
};