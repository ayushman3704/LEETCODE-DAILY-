class Solution { // using sorting
public: 
    bool isAnagram(string s, string t) {
       sort(begin(s), end(s));
       sort(begin(t), end(t));

       return s == t;
    }
};