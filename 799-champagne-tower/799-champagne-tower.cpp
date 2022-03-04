class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        vector<vector<double>>ch;
        
        int i, j;
        
        for(i=0; i<=row; ++i){
            ch.push_back(vector<double>(i+1));
        }
        
        ch[0][0]=poured;
        
        double left, right;
        
        for(i=1; i<=row; ++i){
            
            ch[i][0]=ch[i-1][0]>1.0?((ch[i-1][0]-1.0)/2):0.0;
            
            for(j=1; j<i; ++j){
                ch[i][j]=0.0;
                left = ch[i-1][j-1];
                right = ch[i-1][j];
                if(left>1.0){
                    ch[i][j]+=(left-1.0)/2;
                }
                if(right>1.0){
                    ch[i][j]+=(right-1.0)/2;
                }
            }
            ch[i][j] = ch[i-1][j-1]>1.0?((ch[i-1][j-1]-1.0)/2):0.0;
        }
        
//         for(auto x: ch){
//             for(auto y: x){
//                 cout << y << " ";
//             }
//             cout << endl;
//         }
        
        return min(1.0,ch[row][glass]);
    }
};