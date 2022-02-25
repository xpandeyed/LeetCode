class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size(), i, j, l=0;
        
        bool flag ;
        
        queue<pair<int, int>> q;
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(grid[i][j]==2){
                    q.push(pair<int, int>(i, j));
                }
            }
        }
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        while(!q.empty()){
            int n=q.size();
            
            // cout << l << endl;
            
            flag = false;
            for(i=0; i<n; ++i){
                int x = q.front().first;
                int y = q.front().second;
                // cout << "  " << x << " " << y <<":" << endl;
                visited[x][y]=true;
                q.pop();
                if(x>0 && (visited[x-1][y]==false && grid[x-1][y]==1)){
                    grid[x-1][y]=2;
                    q.push(pair<int, int>(x-1, y));
                    flag=true;
                    // cout << "  " << x-1 << " " << y << endl;
                }
                
                if(y>0 && (visited[x][y-1]==false && grid[x][y-1]==1)){
                    grid[x][y-1]=2;
                    q.push(pair<int, int>(x, y-1));
                    flag=true;
                    // cout << "  "<< x << " " << y-1 << endl;
                }
                
                if(x<rows-1 && visited[x+1][y]==false && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push(pair<int, int>(x+1, y));
                    flag=true;
                    // cout << "  "<<x+1 << " " << y <<endl;
                }
                
                if(y<cols-1 && visited[x][y+1]==false && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push(pair<int, int>(x, y+1));
                    // cout << "  "<<x << " " << y+1 <<endl;
                    flag=true;
                }
            }
            if(flag){
                l++;
            }
        }
        
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return l;
    }
};