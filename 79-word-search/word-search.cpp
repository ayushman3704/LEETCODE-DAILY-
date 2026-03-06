class Solution {  // DFS + Backtracking.
public:
    // Helper function
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // 1. Success Base Case: Agar index word ki length tak pahunch gaya, we found it!
        if (index == word.length()) {
            return true;
        }
        
        // 2. Failure Base Cases: Out of bounds OR character mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // 3. Current cell ka original character save karo
        char temp = board[i][j];
        
        // Mark as visited (taaki issi path mein hum wapas isi cell par na aa jayein)
        board[i][j] = '*';
        
        // 4. Explore 4 directions for the NEXT character (index + 1)
        // Agar kisi bhi direction se 'true' aata hai, toh final result true hoga
        bool found = dfs(board, word, i + 1, j, index + 1) || // Down
                     dfs(board, word, i - 1, j, index + 1) || // Up
                     dfs(board, word, i, j + 1, index + 1) || // Right
                     dfs(board, word, i, j - 1, index + 1);   // Left
                     
        // 5. THE MAGIC STEP (BACKTRACKING): 
        // Wapas aate waqt grid ko uski original state mein restore kardo
        board[i][j] = temp;
        
        // Return whatever result we got from our exploration
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Matrix ke har cell ko check karo as a potential starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Agar pehla character match ho, tabhi DFS call karo
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0) == true) {
                        return true; // Pura word mil gaya!
                    }
                }
            }
        }
        return false; // Sab try kar liya, nahi mila
    }
};