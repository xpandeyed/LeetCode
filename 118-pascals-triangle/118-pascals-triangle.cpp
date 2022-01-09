class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back(vector<int>(1, 1));
        int n=1;
        while(n<numRows){
            vector<int> temp;
            temp.push_back(1);
            for(int i=1; i<n; ++i){
                temp.push_back(res[n-1][i-1]+res[n-1][i]);
            }
            temp.push_back(1);
            res.push_back(temp);
            n++;
        }
        return res;
    }
};