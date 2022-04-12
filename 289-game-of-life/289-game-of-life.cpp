class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(), cols=board[0].size(), i, j, live, dead;
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                live=0;
                dead=0;
                // cout << i << " " << j << endl;
                //left
                if(j-1>-1){
                    if(board[i][j-1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //right
                if(j+1<cols){
                    if(board[i][j+1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //top
                if(i-1>-1){
                    if(board[i-1][j]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //bottom
                if(i+1<rows){
                    if(board[i+1][j]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //top-left
                if(i-1>-1 and j-1>-1){
                    if(board[i-1][j-1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //bottom-left
                if(i+1<rows and j-1>-1){
                    if(board[i+1][j-1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                //top-right
                if(i-1>-1 and j+1<cols){
                    if(board[i-1][j+1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                
                //bottom-right
                if(i+1<rows and j+1<cols){
                    if(board[i+1][j+1]){
                        live++;
                    }else{
                        dead++;
                    }
                }
                // cout << "h" << endl;
                if(live<2){
                    res[i][j]=0;
                }else if(board[i][j] and (live==2 or live==3)){
                    res[i][j]=1;
                }else if(board[i][j] and live>3){
                    res[i][j]=0;
                }else if(board[i][j]==0 and live==3){
                    res[i][j]=1;
                }
            }
        }
        // cout << "f" <<endl;
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                board[i][j]=res[i][j];
            }
        }
    }
};