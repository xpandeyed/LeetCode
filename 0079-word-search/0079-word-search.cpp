class Solution {
public:
    int rows, cols, n;
    
    
    bool dfs(vector<vector<char>>& board, string &word, int r, int c){
        if(word==""){
            return true;
        }
        int ar1[] = {0, 1, 0, -1};
        int ar2[] = {1, 0, -1, 0};
        
        if(r>=rows or c>=cols or r<0 or c<0){
            return false;
        }

        if(board[r][c]!=word[0]){
            return false;
        }

        char curr = board[r][c];
        board[r][c] = '*';
        bool res = false;
        string w = word.substr(1);
        for(int j=0; j<4; ++j){
            res |= dfs(board, w, r+ar1[j], c+ar2[j]);
        }
        board[r][c] = curr;
        return res;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size(), cols=board[0].size();
        int r, c;
        n=word.size();

        for(r=0;r<rows;++r){
            for(c=0;c<cols;++c){
                if(dfs(board, word, r, c)){
                    return true;
                }
            }
        }
        return false;
    }
};