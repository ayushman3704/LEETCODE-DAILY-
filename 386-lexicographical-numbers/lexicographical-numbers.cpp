class Solution { // using recurssion
public:
    void solve(int curr, int n, vector<int> &res){
        if(curr > n) // check if starting num [1, 9] is less than n (given number) or not. if not than return 
        return;

        res.push_back(curr); // else push into res

        for(int append = 0; append <= 9; append++){
            int num = (curr*10) + append; // make multiple digit number from curr number
            if(num > n) // if num is greater than given number(n), then return
            return;

            solve(num, n, res); // call func recursively
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int startNum = 1; startNum <= 9; startNum++){
            solve(startNum, n, res); // call recurssiv solve func 
        }

        return res;
    }
};