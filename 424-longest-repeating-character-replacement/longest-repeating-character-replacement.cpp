class Solution { // using sliding window + hashmap
public:
    int characterReplacement(string s, int k) {
        

        int left = 0;
        int right = 0;

        vector<int> freq(26, 0);

        int maxFreq = INT_MIN;
        int maxLen = INT_MIN;

        while(right < s.size()){

            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Replacements = (Current Window Size) - maxFreq
            if((right - left + 1) - maxFreq > k){ // If replacement is greater than k, invalid window condition
                
                freq[s[left] - 'A']--;

                left++;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};