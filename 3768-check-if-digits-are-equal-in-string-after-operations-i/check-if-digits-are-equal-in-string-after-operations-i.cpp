class Solution { // simple approach. T.C-> O(n^2)  SC-> O(1)
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while(n > 2){
            for(int i = 0; i < n-1; i++){
                s[i] = ((s[i]-'0' + s[i+1]-'0')%10)+'0';
            }
            n--;
        }
        if(s[0] == s[1])
        return true;

        return false;
    }
};