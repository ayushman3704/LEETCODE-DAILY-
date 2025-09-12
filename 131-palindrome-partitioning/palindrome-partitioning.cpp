class Solution { // using backtracking. tc O(2^n * n)
public:
    // func to check palindrome using two pointer
    bool isPalindrome(string &s, int l, int r){
        while(l<r){ // l is left pointer initially at 0 and r is right pointer initially at n-1
            if(s[l] != s[r])
            return false;

            l++;
            r--;
        }
        return true;
    }

    // recursion + backtracking func
    void solve(string &s, int ind, vector<string> &temp, vector<vector<string>> &res){
        if(ind == s.length()){
            res.push_back(temp);
            return;
        }

        for(int i = ind; i < s.length(); i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int ind = 0;

        solve(s, ind, temp, res);

        return res;
    }
};