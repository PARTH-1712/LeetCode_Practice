class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board.size();col++){
                if(board[row][col]=='.') continue;
                char val=board[row][col];
                for(int i=0;i<board.size();i++){
                       if(i!=row && board[i][col]==val) return false;
                       if(i!=col && board[row][i]==val) return false;
                }
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        int newrow=3*(row/3)+i;
                        int newcol=3*(col/3)+j;
                        if(board[newrow][newcol]==val){
                            if(newrow!=row || newcol !=col) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};