class Solution {
public:
    bool validRow(vector<vector<char>>& board, int row, int col, int n){
        for(int i=0; i<9; ++i){
            if(i==col){
                continue;
            }
            if(board[row][i]==(n+'0')){
                return false;
            }
        }
        
        return true;
    }
    
    bool validCol(vector<vector<char>>& board, int row, int col, int n){
        for(int i=0; i<9; ++i){
            if(row==i){
                continue;
            }
            if(board[i][col]==(n+'0')){
                return false;
            }
        }
        return true;
    }
    
    bool validBox(vector<vector<char>>& board, int row, int col, int n){
        int startRow, endRow, startCol, endCol, i, j;
        if(row<3){
            startRow=0;
            endRow=2;
        }else if(row<6){
            startRow=3;
            endRow=5;
        }else{
            startRow=6;
            endRow=8;
        }
        
        if(col<3){
            startCol=0;
            endCol=2;
        }else if(col<6){
            startCol=3;
            endCol=5;
        }else{
            startCol=6;
            endCol=8;
        }
        
        for(i=startRow; i<=endRow; ++i){
            for(j=startCol; j<=endCol; ++j){
                if(i==row and j==col){
                    continue;
                }
                if(board[i][j]==(n+'0')){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solution(vector<vector<char>>& board, int row, int col){
        // cout << row << " " << col  << endl;
        if(col==9){
            return solution(board, row+1, 0);
        }
        if(row==9){
            return true;
        }
        if(board[row][col]!='.'){
            return solution(board, row, col+1);
        }
        for(int i=1; i<=9; ++i){
            if((validRow(board, row, col, i) and validCol(board, row, col, i)) and validBox(board, row, col, i)){
                board[row][col]=(i+'0');
                if(solution(board, row, col+1)){
                    return true;
                }
                board[row][col]='.';
            }
            
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solution(board, 0, 0);
    }
};