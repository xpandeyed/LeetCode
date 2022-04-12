class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(), cols=board[0].size(), i, j, live, dead;
        // vector<vector<int>> res(rows, vector<int>(cols, 0));
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                live=0;
                dead=0;
                // cout << i << " " << j << endl;
                //left
                if(j-1>-1){
                    if(board[i][j-1]==1 or board[i][j-1]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f1" << endl;
                //right
                if(j+1<cols){
                    if(board[i][j+1]==1 or board[i][j+1]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f2" << endl;
                
                //top
                if(i-1>-1){
                    if(board[i-1][j]==1 or board[i-1][j]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                // cout << "f3" << endl;
                //bottom
                if(i+1<rows){
                    if(board[i+1][j]==1 or board[i+1][j]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f4" << endl;
                
                //top-left
                if(i-1>-1 and j-1>-1){
                    if(board[i-1][j-1]==1 or board[i-1][j-1]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f5" << endl;
                //bottom-left
                if(i+1<rows and j-1>-1){
                    if(board[i+1][j-1]==1){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f6" << endl;
                //top-right
                if(i-1>-1 and j+1<cols){
                    if(board[i-1][j+1]==1 or board[i-1][j+1]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f7" << endl;
                
                //bottom-right
                if(i+1<rows and j+1<cols ){
                    if(board[i+1][j+1]==1 or board[i+1][j+1]==-5){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "f8" << endl;
                // cout << "h" << endl;
                if(live<2 and board[i][j]==1){
                    board[i][j]=-5;
                }else if(board[i][j]==1 and (live==2 or live==3)){
                    continue;
                }else if(board[i][j]==1 and live>3){
                    board[i][j]=-5;
                }else if(board[i][j]==0 and live==3){
                    board[i][j]=5;
                }
                // cout << "f9" << endl;
            }
        }
        // cout << "f" <<endl;
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                // cout << board[i][j] << " " ;
                if(board[i][j]==-5){
                    board[i][j]=0;
                }
                if(board[i][j]==5){
                    board[i][j]=1;
                }
            }
            
            // cout << endl;
        }
    }
};