class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int res = 0, n=board.size(), i=n-1, j;
        vector<int> b(1, -2);
        
        while(i>-1){
            for(j=0;j<n and i>-1;++j){
                b.push_back(board[i][j]);
            }
            i--;
            for(j=n-1;j>-1 and i>-1;--j){
                b.push_back(board[i][j]);
            }
            i--;
        }
        
        vector<int> visited(n*n+1, INT_MAX);
        visited[1] = 0;
        
        queue<int> q;
        
        q.push(1);
        
        while(!q.empty()){
            
            res++;
        
            int t=q.size();
            for(j=0;j<t;++j){
                
                int curr = q.front();
                // cout << curr << " " << res << endl;
                q.pop();

                if(curr==n*n) {
                    // cout << "Returning" << endl;
                    return res-1;
                }

                if(b[curr]!=-1 and visited[curr]>res){
                    q.push(b[curr]);
                    visited[b[curr]]=res;
                }

                for(i=1;i<=6;++i){
                    if(curr+i>=n*n) return res;
                    if(visited[curr+i]>res and b[curr+i]==-1){
                        visited[curr+i]=res;
                        q.push(curr+i);
                    }
                    if(b[curr+i]!=-1 and visited[b[curr+i]]>res){
                        if(b[curr+i]>=n*n) return res;
                        visited[b[curr+i]]=res;
                        q.push(b[curr+i]);
                    }
                }
            }
            
        }
        
        return -1;
        
    }
};
// -1 -1 -1
// -1  9  8
// -1  8  9