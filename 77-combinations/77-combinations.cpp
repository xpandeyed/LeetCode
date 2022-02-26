class Solution {
public:
    void rec(int n, int k, vector<vector<int>> &res, vector<int> temp, int i){
        
        int s=temp.size(), ava=n-i+1, req;
        req = k-s;
        
        
        if(req>ava){
            
            return ;
        }
        
        
        if(temp.size()==k){
            res.push_back(temp);
            return ;
        }
        
        
        
        if(i>n){
            return ;
        }
        
        rec(n, k, res, temp, i+1);
        temp.push_back(i);
        rec(n, k, res, temp, i+1);
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        
        rec(n, k, res, temp, 1);
        
        return res;
    }
};