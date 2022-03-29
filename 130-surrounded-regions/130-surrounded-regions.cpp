class Solution {
public:
    
    bool solver(vector<vector<char>>& board, int i, int j, int r, int c, vector<vector<bool>> &visited){
        // cout << "er" << endl;
        if((i>=r or j>=c) or (i<0 or j<0)){
            return false;
        }
        
        if(board[i][j]=='X'){
            return true;
        }
        
        if((i==r-1 or j==c-1) or (i==0 or j==0)){
            return false;
        }
        
        visited[i][j]=true;
        
        bool a = true, b =true, cc = true, d =true;
        
        if(!visited[i-1][j]){
            a = solver(board, i-1, j, r, c , visited);
        }
        
        if(!visited[i][j-1]){
            b = solver(board, i, j-1, r, c , visited);
        }
        
        if(!visited[i+1][j]){
            cc = solver(board, i+1, j, r, c , visited);
        }
        
        if(!visited[i][j+1]){
            d = solver(board, i, j+1, r, c , visited);
        }
        
        return ((a and b) and (cc and d));
        

        
    }
    
    void converter(vector<vector<char>>& board, int i, int j, int r, int c){
        // cout << "con" << endl;
        if((i>=r or j>=c) or (i<0 or j<0)){
            return ;
        }
        
        if(board[i][j]=='X'){
            return ;
        }
        
        board[i][j]='X';
        converter(board, i+1, j, r, c);
        converter(board, i, j+1, r, c);
        converter(board, i-1, j, r, c);
        converter(board, i, j-1, r, c);
    }
    
    void solve(vector<vector<char>>& board) {
        // cout << "solve" << endl;
        int r=board.size(), c=board[0].size(), i, j;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(i=0; i<r; ++i){
            for(j=0; j<c; ++j){
                if(board[i][j]=='X' or visited[i][j]){
                    continue;
                }
                if(solver(board, i, j, r, c, visited)){
                    converter(board, i, j, r, c);
                }
            }
        }
        
    }
};