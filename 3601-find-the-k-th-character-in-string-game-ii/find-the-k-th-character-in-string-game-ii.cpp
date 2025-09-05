class Solution { // using recurssion. This problem is similar to "kth symbol in grammar"
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1) return 'a'; // base case.

        int n = operations.size();
        long long len = 1;
        long long newK = -1;
        long long currOperation = -1;

        for(int i = 0; i < n; i++){
            len *= 2; // as we perform operations on word then every time length of the word gets double

            if(len >= k){ //to find kth char we need at least k sized word
                newK = k - len/2; // k - len/2 th char in the previous word (word[i-1]) will be kth char in the original word
                currOperation = operations[i]; // get current operation to perform
                break;
            }
        }
        char ch = kthCharacter(newK, operations); // recurssion call. 
        if(currOperation == 0) // means ch in original word will be same as in previous word
        return ch;

        return ch == 'z' ? 'a' : ch+1; // else next ch i.e., ch + 1
    }
};