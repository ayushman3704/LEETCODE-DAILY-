class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        for(char & ch : s){
            mp[ch-'a']++;
        }

        for(char & ch : t){
            if(mp.find(ch - 'a') != mp.end()){
                mp[ch-'a']--;

                if(mp[ch-'a'] == 0)
                mp.erase(ch-'a');
            }else{
                return false;
            }
        }
        if(mp.size() == 0)
        return true;

        return false;
    }
};