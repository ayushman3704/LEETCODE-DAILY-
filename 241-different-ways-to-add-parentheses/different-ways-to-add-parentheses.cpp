class Solution { // using recurssion
public:
    vector<int> solve(string s){
        vector<int> res;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '-' || s[i] == '+' || s[i] == '*'){
                vector<int> left_res = solve(s.substr(0, i));
                vector<int> right_res = solve(s.substr(i+1));

                for(int x : left_res){
                    for(int y : right_res){
                         if(s[i] == '+'){
                            res.push_back(x + y);
                        }
                        if(s[i] == '-'){
                            res.push_back(x - y);
                        }
                        if(s[i] == '*'){
                            res.push_back(x * y);
                        }
                    }
                }
            }

        }
        if(res.empty()){
           res.push_back(stoi(s));
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};