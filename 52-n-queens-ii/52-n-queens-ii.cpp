class Solution {
public:
        vector<vector<string>> res;
    
    bool isSafe(int r, int c, int n, vector<vector<string>> board){
        int i;
        
        //Right Check
        for(i=c+1;i<n;++i){
            if(board[r][i]=="Q"){
                return false;
            }
        }
        
        //Left Check
        for(i=c-1;i>-1;--i){
            if(board[r][i]=="Q"){
                return false;
            }
        }
        
        //Top Check
        for(i=r-1;i>-1;--i){
            if(board[i][c]=="Q"){
                return false;
            }
        }
        
        //Bottom Check
        for(i=r+1;i<n;++i){
            if(board[i][c]=="Q"){
                return false;
            }
        }
        
        //Top-Left
        for(i=1; r-i>-1 and c-i>-1; ++i){
            if(board[r-i][c-i]=="Q"){
                return false;
            }
        }
        
        //Bottom Left
        for(i=1; r+i<n and c-i>-1; ++i){
            if(board[r+i][c-i]=="Q"){
                return false;
            }
        }
        //Top-Right
        for(i=1;r-i>-1 and c+i<n; ++i){
            if(board[r-i][c+i]=="Q"){
                return false;
            }
        }
        
        //Bottom-Right
        for(i=1;r+i<n and c+i<n; ++i){
            if(board[r+i][c+i]=="Q"){
                return false;
            }
        }
        
        
        return true;
        
        
    }
    bool place(vector<vector<string>> &board, int r, int c, int n){
        if(r>=n){
            vector<string> currBoard;
            for(auto row: board){
                string currRow="";
                for(auto col: row){
                    currRow+=col;
                }
                currBoard.push_back(currRow);
            }
            res.push_back(currBoard);
            return true;
        }
        if(c>=n){
            return place(board, r+1, 0, n);
        }
        int i;
        for(i=c; i<n; ++i){
            bool safe = isSafe(r, i, n, board);
            // cout << "Safe: " << safe << endl;
            if(safe){
                // cout << "Placing Q at: " << r <<  " " << i << endl;
                board[r][i]="Q";
                place(board, r+1, 0, n);
                board[r][i]=".";
            }
        }
        return false;
        
    }
    int totalNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        place(board, 0, 0, n);
        return res.size();
    }
};