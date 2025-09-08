class Solution {
public:
    // func to check number is non-zero or not
    bool check(int num){ 
        while(num){
            if(num % 10 == 0)
            return false;

            num = num / 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a < n; a++){
            int b = n - a;

            if(check(a) && check(b)){
                return {a, b};
            }
        }
        return {-1};
    }
};