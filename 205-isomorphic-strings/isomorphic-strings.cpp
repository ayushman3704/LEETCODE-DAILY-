class Solution { // using two maps.
public: 
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
        return false;

        unordered_map<char, char> s2t; // it maps char of s to char t
        unordered_map<char, char> t2s; // it maps char of t to char s

        for(int i = 0; i < s.size(); i++){
            
            if(s2t.count(s[i]) && s2t[s[i]] != t[i]) // s[i] exists in s2t map but it does not have correct map with char of t
            return false;

            if(t2s.count(t[i]) && t2s[t[i]] != s[i]) // t[i] exists in t2s map but it does not have correct map with char of s
            return false;

            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }

        return true;
    }
};