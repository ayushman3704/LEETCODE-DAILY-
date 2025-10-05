class Solution { // using sliding window 
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int currUnsat = 0;

        for(int i = 0; i < minutes; i++){ // first window with unsatisfied customers of size 0 to minutes-1
            currUnsat += customers[i]*grumpy[i];
        }

        int maxUnsat = currUnsat;
        int i = 0;
        int j = minutes;

        while(j < n){
            currUnsat += customers[j]*grumpy[j]; // add new element in the window. expanding window
            currUnsat -= customers[i]*grumpy[i]; // constracting window to maintain the size of window

            maxUnsat = max(maxUnsat, currUnsat); // update maxUnsatisfied customers

            i++;
            j++;
        }

        int total = maxUnsat;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                total += customers[i]; // without if condition- total += costomers[i]*(1-grumpy[i]);
            }
        }
        
        return total;
    }
};