class Solution { // Approach - 2. 
public:
    const int M = 1e9 + 7;
    int numSub(string s) {
        int n = s.length();

        int count = 0;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                count++;

                res = (res + count) % M;
            }else{
                count = 0;
            }
        }

        return res;
    }
};