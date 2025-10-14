class Solution { // recursion + memoization. take or not take waala type hai. pattern- Knapsack (0/1, Unbounded, Variants)
public:
    int t[301][5001];
    int solve(int amount, vector<int>& coins, int i){
        if(amount == 0){
            return 1;
        }
        if(i >= coins.size() || amount < 0)
        return 0;

        if(t[i][amount] != -1)
        return t[i][amount];

        int take = solve(amount - coins[i], coins, i);
        int not_take = solve(amount, coins, i+1);

        return t[i][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));

        int res = solve(amount, coins, 0);

        return res;
    }
};