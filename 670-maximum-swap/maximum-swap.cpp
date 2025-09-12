class Solution { 
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int n = s.length();

        vector<int> rightMax(n); // store maximum element to right of every element (char in string s)
        rightMax[n-1] = n-1; 

        for(int i = n-2; i >= 0; i--){
            int maxRightInd = rightMax[i+1];
            int maxRightNum = s[maxRightInd];

            rightMax[i] = (s[i] > maxRightNum) ? i : maxRightInd;
        }

        for(int i = 0; i < n; i++){
            int rightMaxInd = rightMax[i];
            int rightMaxNum = s[rightMaxInd];

            if(s[i] < rightMaxNum){
                swap(s[i], s[rightMaxInd]);
                return stoi(s);
            }
        }
        return num;
    }
};

// revise it 