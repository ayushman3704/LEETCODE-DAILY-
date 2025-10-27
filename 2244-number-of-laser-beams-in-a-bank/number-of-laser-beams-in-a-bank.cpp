class Solution { // string problem
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int res = 0;
        int prevSecurityDevice = 0;

        for(int i = 0; i < n; i++){
            int currSecurityDevice = 0;

            for(auto & ch : bank[i]){
                if(ch == '1')
                currSecurityDevice++;
            }

            res += currSecurityDevice * prevSecurityDevice;

            if(currSecurityDevice != 0)
            prevSecurityDevice = currSecurityDevice;
        }
        return res;
    }
};