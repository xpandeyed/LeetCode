class Solution {
public:
    void rec(int k, int n, int m, vector<int> curr, vector<vector<int>> &res){
        if(k<=0){
            return;
        }
        if(n<=0){
            return;
        }
        if(n<=m){
            return;
        }
        if(k<=1 and n>9){
            return ;
        }
        if(n>m and k==1){
            curr.push_back(n);
            res.push_back(curr);
            return;
        }
        int i;
        for(i=m+1; n-i>m; ++i){
            curr.push_back(i);
            rec(k-1, n-i, i, curr, res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        rec(k, n, 0, curr, res);
        return res;
    }
};