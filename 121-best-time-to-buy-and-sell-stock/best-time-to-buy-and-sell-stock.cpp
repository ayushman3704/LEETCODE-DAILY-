class Solution { // consider every day as selling day. and then calculate profit
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = prices[0]; // minimum price from index 0 to selling day - 1
        int maxProfit = 0; // maximum profit till selling day

        for(int i = 1; i < n; i++){
            int profit = prices[i] - mini;

            maxProfit = max(maxProfit, profit);

            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};