class Solution {
public:
    int largestRectangleInHistogram(vector<int> heights){
        stack<int> s;
        int n=heights.size(), i, res=0, curr, tp, r, l;
        
        for(i=0; i<n; ++i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                tp = s.top();
                s.pop();
                curr = heights[tp];
                r=0;
                r+=(curr*(i-tp-1));
                l=0;
                if(!s.empty()){
                    l+=(curr*(tp-s.top()-1));
                }else{
                    l+=(curr*tp);
                }
                curr+=l;
                curr+=r;
                
                                
                //cout << heights[i] << " " << curr << endl;
                
                
                res = max(res, curr);
            }
            
            s.push(i);
        }
        
        
        while(!s.empty()){
            tp = s.top();
            s.pop();
            curr = (n-tp)*heights[tp];
            if(!s.empty()){
                curr+=(heights[tp]*(tp-s.top()-1));
            }else{
                curr+=(heights[tp]*tp);
            }
            res = max(res, curr);
        }
        return res;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), i, j, res;
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for(i=0; i<rows; ++i){
            for(j=0; j<cols; ++j){
                grid[i][j]=matrix[i][j]-48;
            }
        }
        
        for(i=1; i<rows; ++i){
            for(j=0; j<cols; ++j){
                if(grid[i][j]!=0){
                    grid[i][j]+=grid[i-1][j];
                }
            }
        }
        
        for(auto x: grid){
            res = max(res, largestRectangleInHistogram(x));
        }
        
        return res;
        
    }
};