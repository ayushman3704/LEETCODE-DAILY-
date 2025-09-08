class Solution { // using recursion and backtracking. approach 2 optimal approach
                // T.C O(2^n)
                // s.c O(2n)
public:
    vector<string> result;
    // // func to check valid parentheses
    // bool isValid(string &curr){
    //     int count = 0;

    //     for(char ch : curr){
    //         if(ch == '(')
    //         count++;

    //         else
    //         count--;

    //         if(count < 0)
    //         return false;
    //     }
    //     return count == 0;
    // }
    void solve(string &curr, int n, int open, int close){
        if(curr.length() == 2*n){
            result.push_back(curr);

            return;
        }

        if(open < n){
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        } 

        if(close < open){
            curr.push_back(')');
            solve(curr, n, open, close+1);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;

        string str = "";
        solve(str, n, open, close);

        return result;
    }
};