class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=rows, r, c, count=0;
        if(grid[0][0]==1){
            return -1;
        }
        if(grid[rows-1][cols-1]==1){
            return -1;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()){
            count++;
            int n=q.size(), i;
            for(i=0; i<n; ++i){
                auto p = q.front();
                q.pop();
                r = p.first;
                c = p.second;
                if(r==rows-1 and c==cols-1){
                    return count;
                }

                for(int x=-1; x<2; ++x){
                    for(int y=-1; y<2; ++y){
                        if(((r+x<rows and r+x>-1) and (c+y<cols and c+y>-1)) and grid[r+x][c+y]==0){
                            q.push({r+x, c+y});
                            grid[r+x][c+y]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};