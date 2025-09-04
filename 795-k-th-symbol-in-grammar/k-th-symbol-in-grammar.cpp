class Solution { // using recursion.
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) // base case
        return 0;

        int length = pow(2, n-1);
        if(k <= length/2){
           return kthGrammar(n-1, k);
        }

        return !kthGrammar(n-1, k-(length/2));
    }
};