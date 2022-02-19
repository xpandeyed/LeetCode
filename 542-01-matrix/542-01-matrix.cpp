class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols=mat[0].size(), i , j;
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(mat[i][j]==0){
                    q.push(pair<int, int>(i, j));
                    visited[i][j]=true;
                }
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            if(x-1>=0 && visited[x-1][y]==false){
                res[x-1][y] = res[x][y]+1;
                visited[x-1][y]=true;
                q.push(pair<int, int>(x-1, y));
            }
            if(y-1>=0 && visited[x][y-1]==false){
                res[x][y-1] = res[x][y]+1;
                visited[x][y-1]=true;
                q.push(pair<int, int>(x, y-1));
            }
            if(x+1<rows && visited[x+1][y]==false){
                res[x+1][y] = res[x][y]+1;
                visited[x+1][y]=true;
                q.push(pair<int, int>(x+1, y));
            }
            if(y+1<cols && visited[x][y+1]==false){
                res[x][y+1] = res[x][y]+1;
                visited[x][y+1] = true;
                q.push(pair<int, int>(x, y+1));
            }
            
        }
        
        return res;
    }
};