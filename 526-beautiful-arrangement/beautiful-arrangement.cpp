class Solution { // Backtracking (PERMUTATIONS WITH CONSTRAINTS)
public:
    int count;
    void solve(int pos, int n, vector<bool> vis){

        if(pos > n){ // base case
            count++;
            return;
        }

        for(int i = 1; i <= n; i++){

            if(vis[i]) continue;

            if(pos % i == 0 || i % pos == 0){ // constrain check
                vis[i] = true; // do

                solve(pos + 1, n, vis); // explore

                vis[i] = false; // undo
            }
        }
    }
    int countArrangement(int n) {
        
        vector<bool> vis(n+1, false);

        solve(1, n, vis);

        return count;
    }
};