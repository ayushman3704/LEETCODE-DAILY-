class Solution { // using mathematics 
public:
    int totalMoney(int n) {
        int terms = n/7; // complete Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //Final week remaining days = n%7
        int start_money = 1 + terms;

        for(int day = 1; day <= (n%7); day++) {
            result += start_money;
            start_money++;
        }

        return result;
    }
};