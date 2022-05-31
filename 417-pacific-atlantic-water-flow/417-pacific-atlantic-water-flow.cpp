class Solution {
public:
    int rows , cols;

    void p(vector<vector<int>>& heights, int r, int c, vector<vector<int>> &pac){
        int ar1[] = {1, 0, -1, 0};
        int ar2[] = {0, 1, 0, -1};
        pac[r][c]=1;
        for(int i=0;i<4; ++i){
            if(((r+ar1[i]<rows and r+ar1[i]>-1) and (c+ar2[i]<cols and c+ar2[i]>-1))and (pac[r+ar1[i]][c+ar2[i]]==0 and heights[r+ar1[i]][c+ar2[i]]>=heights[r][c])){
                p(heights, r+ar1[i], c+ar2[i], pac);
            }
        }
    }
    void a(vector<vector<int>>& heights, int r, int c, vector<vector<int>> &atl){
        int ar1[] = {1, 0, -1, 0};
        int ar2[] = {0, 1, 0, -1};
        atl[r][c]=1;
        for(int i=0;i<4; ++i){
            if(((r+ar1[i]<rows and r+ar1[i]>-1) and (c+ar2[i]<cols and c+ar2[i]>-1))and (atl[r+ar1[i]][c+ar2[i]]==0 and heights[r+ar1[i]][c+ar2[i]]>=heights[r][c])){
                a(heights, r+ar1[i], c+ar2[i], atl);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        vector<vector<int>> res;
        cols=heights[0].size();
        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));
        int i, j;
        for(i=0;i<rows;++i){
            p(heights, i, 0, pac);
            a(heights, i, cols-1, atl);
        }
        for(i=0;i<cols;++i){
            p(heights, 0, i, pac);
            a(heights, rows-1, i, atl);
        }
        for(i=0;i<rows;++i){
            for(j=0;j<cols;++j){
                pac[i][j]+=atl[i][j];
                if(pac[i][j]==2){
                    res.push_back({i, j});
                }
            }
        }
        return res;
        
    }
};