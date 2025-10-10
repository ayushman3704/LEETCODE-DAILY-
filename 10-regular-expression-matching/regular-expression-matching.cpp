class Solution { // using recursion + memoization
public:
    int t[21][21];
    
    bool solve(int i, int j, string &s, string &p){
        if(j == p.length())
        return (i == s.length());

        if(t[i][j] != -1)
        return t[i][j];

        bool ans = false;

        bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.length() && p[j+1] == '*'){ // Best example to understand : s = "aaab", p = "a*b"
            ans = (solve(i, j+2, s, p) || (first_match && solve(i+1, j, s, p)));
        }else{ // no * in pattern string
            ans = (first_match && solve(i+1, j+1, s, p));
        }
        return t[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));

        return solve(0, 0, s, p);
    }
};