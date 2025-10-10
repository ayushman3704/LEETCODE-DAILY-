class Solution { // using recursion + memoization. 2-D DP
public:
    int t[101][101];

    bool solve(int i, int j, string& s1, string& s2, string& s3){
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();

        if(i == n && j == m && i+j == N)
        return true;

        if(i+j >= N)
        return false;

        if(t[i][j] != -1)
        return t[i][j];

        bool result = false;

        if(s1[i] == s3[i+j]){
            result = solve(i+1, j, s1, s2, s3);
        }

        if(result == true) // optional, slight optimization
        return t[i][j] = result;

        if(s2[j] == s3[i+j]){
            result = solve(i, j+1, s1, s2, s3);
        }

        return t[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));

        // i -> pointing to s1, j -> pointing to s2, i+j -> pointing to s3
        return solve(0, 0, s1, s2, s3);
    }
};