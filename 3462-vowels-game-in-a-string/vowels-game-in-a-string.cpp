class Solution {
public:
    bool doesAliceWin(string s) {
        // string temp;

        // for(char ch : s){
        //     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        //     temp.push_back(ch);
        // } 

        // // if((temp.length() >= 1)|| temp.length() == s.length())
        // // return true;

        // // else if(temp.length() == 1 || temp.length() % 2 == 1)
        // // return true;

        // // else if(temp.length() == 0 || temp.length() % 2 == 1)

        // if(temp.length() == 0)
        // return false;

        // return true;



        return any_of(s.begin(), s.end(), [](char ch){
            return string("aeiou").find(ch) != string::npos;
        });
    }
};