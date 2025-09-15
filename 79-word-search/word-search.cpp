class Solution { // using backtracking
public:
    int m;
    int n;
    vector<vector<int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx){
        if(idx == word.length())
        return true;

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ind = 0;
        m = board.size();
        n = board[0].size();

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};