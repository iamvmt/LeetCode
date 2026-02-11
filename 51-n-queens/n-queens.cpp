class Solution {
public:

    void backtrack(int row, int n, vector<int> &pos, vector<vector<string>> &res){
        if(row == n){
            res.push_back(build(pos, n));
            return;
        }
        for(int col = 0; col < n; col++){

            if(isValid(row, col, pos)){

                pos[row] = col;
                backtrack(row + 1, n, pos, res);
                pos[row] = -1;

            }
        }
    }


    bool isValid(int row, int col, vector<int> &pos){
        for(int i = 0; i < row; i++){
            //column
            if(pos[i] == col) return false;
            //diagonals
            if(abs(row - i) == abs(col - pos[i]))
                return false;
        }
        return true;
    }


    vector<string> build(vector<int> &pos, int n){
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][pos[i]] = 'Q';
        }
        return board;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        backtrack(0, n, pos, res);
        return res;
    }
};