class Solution { // backtracking. take or not take
public:     
    int res = INT_MAX;
    int n;

    void solve(vector<int>& cookies, int ind, vector<int> &children, int k){
        if(ind >= n){
            int unfairness = *max_element(begin(children), end(children));

            res = min(res, unfairness);
            return;
        }

        int cookie = cookies[ind];
        for(int i = 0; i < k; i++){
            children[i] += cookie;

            solve(cookies, ind+1, children, k);

            children[i] -= cookie;

        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> children(k, 0);

        solve(cookies, 0, children, k);

        return res;
    }
};