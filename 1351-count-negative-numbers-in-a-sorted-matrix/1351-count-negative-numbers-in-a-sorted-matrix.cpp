class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size(), i, res=0, l, r, m;
        for(i=0; i<rows; ++i){
            if(grid[i][0]<0){
                res+=cols;
            }else if(grid[i][cols-1]>=0){
                continue;
            }else{
                l=0;
                r=cols-1;
                while(l<r){
                    m=(l+r)/2;
                    if(grid[i][m]>=0){
                        l=m+1;
                    }else{
                        r=m;
                    }
                }
                res+=(cols-l);
            }
        }
        return res;
    }
};