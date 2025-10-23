class Solution { // using bottom up. Space optimization
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> t = triangle[n-1];

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col <= row; col++){
                t[col] = triangle[row][col] + min(t[col], t[col+1]);
            }
        }
        return t[0];
    }
};