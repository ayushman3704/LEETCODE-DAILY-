class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_set<int> setA, setB;

        vector<int> ans(A.size());

        int common = 0;

        for(int i = 0; i < A.size(); i++){

            if(A[i] == B[i])
            common++;

            else{

                if(setA.count(B[i]))
                common++;

                if(setB.count(A[i]))
                common++;
            }

            setA.insert(A[i]);
            setB.insert(B[i]);

            ans[i] = common;
        }

        return ans;
    }
};