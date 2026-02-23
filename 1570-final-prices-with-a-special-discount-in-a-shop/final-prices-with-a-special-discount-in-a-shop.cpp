class Solution { // using monotonic stack. Pattern- Next Smaller or Equal Element to the Right
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> st; // stack to store indices

        for(int i = 0; i < prices.size(); i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return prices;
    }
};