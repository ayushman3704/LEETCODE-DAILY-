class Solution { // using two for loop.
public:
    int countTriples(int n) {
        int cnt = 0;

        for(int a = 1; a <= n; a++){
            for(int b = a+1; b <= n; b++){
                int cSquare = (a*a) + (b*b);

                int x = sqrt(cSquare);
                if(x*x == cSquare && x <= n){
                    cnt += 2;
                }
            }
        }
        return cnt;
    }
};