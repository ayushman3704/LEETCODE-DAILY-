class Solution { // Approach- expand around centre. for odd length string cenntre character will be one. For even length string centre character will be two
public:
    string expand(string s, int left, int right){ // Generate palindrom around the centre character. 

        while(left >= 0 && right <= s.length() && s[left] == s[right]){

            left--;
            right++;
        }

        return s.substr(left + 1, right-left-1);
    }

    string longestPalindrome(string s) {
        
        string res = "";

        if(s.length() == 0) return "";

        for(int i = 0; i < s.length(); i++){

            string p1 = expand(s, i, i); // odd length

            string p2 = expand(s, i, i+1); // even length

            if(p1.length() > res.length())
            res = p1;

            if(p2.length() > res.length())
            res = p2;
        }
        return res;
    }
};