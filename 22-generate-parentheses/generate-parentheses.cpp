class Solution { // using recursion and backtracking
                // T.C O(2^n * 2n)
                // s.c O(2n)
public:
    vector<string> result;
    // func to check valid parentheses
    bool isValid(string &curr){
        int count = 0;

        for(char ch : curr){
            if(ch == '(')
            count++;

            else
            count--;

            if(count < 0)
            return false;
        }
        return count == 0;
    }
    void solve(string &curr, int n){
        if(curr.length() == 2*n){
            if(isValid(curr))
            result.push_back(curr);

            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back(); 

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        solve(str, n);

        return result;
    }
};