class Solution { // using backtracking
public:
    vector<string> res;
    unordered_map<string,int> mp;

     //func to find min invalid parentheses
    int countValid(string s){
        stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
    }

    void solve(string s, int minInValid){
         if(mp[s] != 0) 
            return;
        else
            mp[s]++; //mp[s] = 1

        if(minInValid < 0)
        return;

        if(minInValid == 0){
            if(!countValid(s))
            res.push_back(s);

            return;
        }

        for(int i = 0; i< s.length(); i++){
            string left = s.substr(0, i);
            string right = s.substr(i+1);

            solve(left + right, minInValid-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s, countValid(s));
        return res;
    }
};