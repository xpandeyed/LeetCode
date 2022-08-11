class Solution {
public:
    
    queue<pair<pair<int, int>, int>> q;
    
    void turnTwo(vector<vector<int>>& grid, int r, int c, int rows, int cols){
        if(r<0 or c<0 or r>=rows or c>=cols){
            return ;
        }
        if(grid[r][c]!=1) return;
        grid[r][c]=2;
        q.push(make_pair(make_pair(r, c), 0));
        int arr1[] = {1, -1, 0, 0};
        int arr2[] = {0, 0, -1, 1};
        for(int i=0;i<4;++i){
            turnTwo(grid, r+arr1[i], c+arr2[i], rows, cols);
        }
        
    }
    
//     void dfs(vector<vector<int>>& grid, int rows, int cols, int r, int c, int d, vector<vector<bool>> visited){
//         if(r>=rows or c>=cols or r<0 or c<0) return ;
//         if(d>=res) return ;
//         if(visited[r][c]) return ;
//         if(grid[r][c]==2) return ;
//         if(grid[r][c]==1){
//             res = min(res, d);
//             return;
//         }
//         visited[r][c]=true;

//         int arr1[] = {1, -1, 0, 0};
//         int arr2[] = {0, 0, -1, 1};
//         for(int i=0;i<4;++i){
//             dfs(grid, rows, cols, r+arr1[i], c+arr2[i], d+1, visited);
//         }
//     }
    
//     void bfs(vector<vector<int>>& grid, int rows, int cols, int r, int c){
//         queue<pair<pair<int, int>, int>> que;
//         que.push(make_pair(make_pair(r, c), 0));
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//         int arr1[] = {0, -1, 0, 1};
//         int arr2[] = {1, 0, -1, 0};
//         while(!que.empty()){
//             auto p = que.front();
//             auto cor = p.first;
//             // cout << cor.first << " " << cor.second << endl;
//             int dis = p.second;
//             que.pop();
//             int r1 , c1;
//             for(int i=0; i<4; ++i){
//                 r1 = cor.first+arr1[i];
//                 c1 = cor.second+arr2[i];
//                 if(r1>=rows or c1>=cols or r1<0 or c1<0) continue ;
//                 if(grid[r1][c1]==1){
//                     // cout << r1 << " " << c1 << " : " << dis << endl;
//                     res = min(res, dis);
//                     return ;
//                 }
//                 if(grid[r1][c1]==2) continue;
//                 if(visited[r1][c1]) continue;
                
//                 visited[r1][c1] = true;
//                 auto temp = make_pair(r1, c1);
//                 p = make_pair(temp, dis+1);
                
//                 // cout << "Pushing: "<<cor.first << " " << cor.second << " dis: " << dis+1  << endl;

//                 que.push(p);
//             }
//         }
//     }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), r, c, dis;
        for(r=0;r<rows;++r){
            for(c=0;c<cols;++c){
                if(grid[r][c]==1){
                    turnTwo(grid, r, c, rows, cols);
                    c=cols;
                    r=rows;
                }
            }
        }
        //Now one of the islands is turnded into tows and now we have to connect ones and twos
        // for(auto x: grid){
        //     for(auto y: x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0;i<n;++i){
                
                auto t = q.front();
                auto cor = t.first;
                
                dis = t.second;
                
                r = cor.first;
                c = cor.second;
                
                q.pop();
                
                int arr1[] = {1, -1, 0, 0};
                int arr2[] = {0, 0, -1, 1};
                
                for(int j=0;j<4;++j){
                    int r1 = r+arr1[j];
                    int c1 = c+arr2[j];
                    
                    if(r1<0 or c1<0 or r1>=rows or c1>=cols) continue;
                    
                    if(grid[r1][c1]==1){
                        return dis;
                    }
                    if(grid[r1][c1]==0){
                        grid[r1][c1]=2;
                        auto temp = make_pair(r1, c1);
                        q.push(make_pair(temp, dis+1));
                    }
                    
                }
                
            }
            
            
            // bfs(grid, rows, cols, r, c);
            
            
            // for(int i=0; i<4; ++i){
            //     // dfs(grid, rows, cols, r+arr1[i], c+arr2[i], 0, visited);
            // }
        }
        
        return dis;
    }
};
//4 3 : 1