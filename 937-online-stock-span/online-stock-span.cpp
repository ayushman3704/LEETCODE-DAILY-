class StockSpanner { // using monotonic stack
private: 
    stack<pair<int, int>> st;  // stack stores pairs of {price, span}
public:
    StockSpanner() {
        // nothing to initialize
    }
    
    int next(int price) {
        int span = 1;

        // pop all prices <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // accumulate their spans
            st.pop();
        }

        // push current price with its computed span
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */