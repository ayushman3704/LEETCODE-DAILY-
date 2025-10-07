class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int l = 0;
        int r = s.length() - 1;

        while(l<r){ // l is left pointer initially at 0 and r is right pointer initially at n-1
            if(s[l] != s[r])
            return false;

            l++;
            r--;
        }
        return true;
    }
};