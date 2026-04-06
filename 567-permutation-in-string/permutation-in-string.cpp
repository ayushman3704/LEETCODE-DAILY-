class Solution { // using fixed sized window + hashmap
public:
    bool checkInclusion(string s1, string s2) {
        
        int k = s1.size();
        int n = s2.size();

        if(k > n)
        return false;

        vector<int> s1Freq(26, 0);

        vector<int> windowFreq(26, 0);

        for(int i = 0; i < k; i++){

            s1Freq[s1[i] - 'a']++; 

            windowFreq[s2[i] - 'a']++;
        }

        if(s1Freq == windowFreq)
        return true;

        for(int i = k; i < n; i++){

            windowFreq[s2[i] - 'a']++;

            windowFreq[s2[i - k] - 'a']--;

            if(s1Freq == windowFreq)
            return true;
        }

        return false;
    }
};