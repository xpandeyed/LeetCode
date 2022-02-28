class Solution {
public:
    int dynamic(vector<vector<int>> t){
        int n=t.size(), i, j;
        
        vector<vector<int>> res(n, vector<int>(n, INT_MAX));
        
        for(i=0; i<n; ++i){
            res[n-1][i]=t[n-1][i];
        }
        
        for(i=n-2; i>-1; --i){
            for(j=0; j<=i; ++j){
                res[i][j] = t[i][j]+min(res[i+1][j], res[i+1][j+1]);
            }
        }
        
        // for(auto x: res){
        //     for(int y: x){
        //         cout << y << " "; 
        //     }
        //     cout << endl;
        // }
        
        return res[0][0];
    }
    
    int rec(vector<vector<int>> t, int r, int i, int n, vector<vector<int>> &res){
        if(r==n-1){
            return res[r][i] = t[r][i];
        }
        
        if(res[r][i]!=-1){
            return res[r][i];
        }
        
        int a = t[r][i]+rec(t, r+1, i+1, n, res);
        int b = t[r][i]+rec(t, r+1, i, n, res);
        
        return res[r][i] = min(a, b);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> res(n, vector<int>(n, -1));
        return dynamic(triangle);
    }
};