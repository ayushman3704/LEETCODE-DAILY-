class Solution { // using recursion + memoization
public:
    int t[101][101][201];

    bool solve(int i, int j, int k, string& s1, string& s2, string& s3){
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();

        if(i == n && j == m && k == N)
        return true;

        if(k >= N)
        return false;

        if(t[i][j][k] != -1)
        return t[i][j][k];

        bool result = false;

        if(s1[i] == s3[k]){
            result = solve(i+1, j, k+1, s1, s2, s3);
        }

        if(result == true) // optional, slight optimization
        return t[i][j][k] = result;

        if(s2[j] == s3[k]){
            result = solve(i, j+1, k+1, s1, s2, s3);
        }

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));

        // i -> pointing to s1, j -> pointing to s2, k -> pointing to s3
        return solve(0, 0, 0, s1, s2, s3);
    }
};