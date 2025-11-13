class Solution { // traverse string left to right to find  maximum number of operations.
               // to find minimum number of operations traverse right to left
public:
    int maxOperations(string s) {
        int n = s.length();
        
        int operations = 0;
        int cnt = 0; // zero phle jitne bhi 1 hai uska count nikal lo aur zero aate hi result (operations) me add kr do
        int i = 0;

        while(i < n){
            if(s[i] == '0'){
                operations += cnt; // jaise hi zero aaya operations me add kr diye

                while(i < n && s[i] == '0') // to skip consecutive 0 after 1
                i++;
            }else{
                cnt++;
                i++;
            }
        }
        return operations;
    }
};