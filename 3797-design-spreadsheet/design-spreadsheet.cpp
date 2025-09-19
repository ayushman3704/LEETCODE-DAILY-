class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));    
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A'; // find column, do -'A' to convert it into integer
        int row = stoi(cell.substr(1)) - 1; // find row, we do -1 to convert 1 based indexing into 0 based indexing

        sheet[row][col] = value;

    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    // utility func to find that string left or right is digit or cell 
    int solve(string &s) {
        if(isdigit(s[0])) { // if string is digit then just return it
            return stoi(s);
        }

        // if string is cell then return integer value from that cell
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }

    int getValue(string formula) {
        //Example : "=X+Y"
        string s = formula.substr(1); // remove =, get "X + Y" sting only
        int plusIdx = s.find('+'); // find index of plus sign in the string s

        string left = s.substr(0, plusIdx); // string before plus sign 
        string right = s.substr(plusIdx+1); // string after plus sign


        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */