class Solution {
public:
    
    bool checkInBox(vector<vector<char>>& board, int sRow, int sCol, int endRow, int endCol){
        
        int i, j;
        
        set<char> s;
        
        for(i=sRow; i<=endRow; ++i){
            for(j=sCol; j<=endCol; ++j){
                
                if(board[i][j]=='.'){
                    continue;
                }
                
                if(s.find(board[i][j])!=s.end()){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, n=9, t;
        for(i=0;i<n; ++i){
            for(j=0; j<n; ++j){
                
                if(board[i][j]=='.'){
                    continue;
                }
                
                //go up
                t=i-1;
                while(t>=0){
                    if(board[t][j]==board[i][j]){
                        return false;
                    }
                    t--;
                }
                
                
                //go down
                t=i+1;
                while(t<9){
                    if(board[t][j]==board[i][j]){
                        return false;
                    }
                    t++;
                }
                
                //go right
                t=j+1;
                while(t<9){
                    if(board[i][t]==board[i][j]){
                        return false;
                    }
                    t++;
                }
                
                //go left
                t=j-1;
                while(t>=0){
                    if(board[i][t]==board[i][j]){
                        return false;
                    }
                    t--;
                }
                
            }
        }
        
        
        for(i=0; i<=6; i+=3){
            for(j=0; j<=6; j+=3){
                if(checkInBox(board, i, j, i+2, j+2)==false){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};