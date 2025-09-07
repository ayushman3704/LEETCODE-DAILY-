class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int elem = 1;
        int i = 0;
        while(i+1 < n){
            res[i] = elem;
            res[i+1] = 0 - elem;

            elem++;
            i += 2;
        }

        if(n % 2 != 0){
            res[n-1] = 0;
        }

        return res;
    }
};