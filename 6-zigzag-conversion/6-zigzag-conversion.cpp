class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size(), i=0, row=0, col=1;
        if(numRows==1){
            return s;
        }
        vector<vector<char>> temp(numRows, vector<char>(n, '1'));
        while(i<n){
            // cout << i << endl;
            if(row){
                row=1;
            }
            col--;
            while(i<n and row<numRows){
                temp[row][col]=s[i];
                row++;
                // cout << "b" << endl;
                i++;
            }
            row-=2;
            col++;
            while(i<n and row>-1){
                temp[row][col]=s[i];
                row--;
                // cout << "b" << endl;
                col++;
                i++;
            }
        }
        string res = "";
        i=0;
        for(row=0; row<numRows and i<n; ++row){
            for(col=0; col<n and i<n; ++col){
                // cout << temp[row][col] << " ";
                if(temp[row][col]!='1'){
                    res+=temp[row][col];
                    i++;
                }
            }
            
            // cout << endl;
        }
        
        return res;
    }
};