class Solution { // using memoization approach
public:
    int M = 1e9 + 7;

    // func to find total no. of people contribute on day 'day'
    int solve(int day, vector<int> &t, int delay, int forget){
        if(day == 1)
        return 1;

        if(t[day] != -1)
        return t[day];

        int result = 0;
        for(int prev = day - forget + 1; prev <= day - delay; prev++){
            if(prev > 0)
            result = (result + solve(prev, t, delay, forget)) % M;
        }
        return t[day] = result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;

        vector<int> t(n+1, -1);
        
        for(int day = n-forget+1; day <= n; day++){
            if(day > 0)
            total = (total + solve(day, t, delay, forget))%M;
        }
        return total;
    }
};