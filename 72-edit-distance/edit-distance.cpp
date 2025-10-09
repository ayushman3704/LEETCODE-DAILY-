class Solution { // using recursion + memoization
public:
    int t[501][501];
    int solve(string& word1, string& word2, int i, int j){
        int n = word1.size();
        int m = word2.size();

        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }

        if(t[i][j] != -1)
        return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = solve(word1, word2, i+1, j+1);
        }else{
            int insertChar = 1 + solve(word1, word2, i, j+1);
            int deleteChar = 1 + solve(word1, word2, i+1, j);
            int replaceChar = 1 + solve(word1, word2, i+1, j+1);

            return t[i][j] = min({insertChar, deleteChar, replaceChar});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        memset(t, -1, sizeof(t));

        return solve(word1, word2, 0, 0);
    }
};