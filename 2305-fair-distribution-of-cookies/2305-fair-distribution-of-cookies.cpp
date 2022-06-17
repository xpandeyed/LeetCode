class Solution {
public:
    int ans = INT_MAX;
    void rec(vector<int>& cookies, vector<int> &child, int i, int k, int n){
        if(i==n){
            int temp = child[0];
            for(int x: child){
                temp=max(temp, x);
            }
            ans = min(temp, ans);
            return;
        }
        for(int j=0;j<k;++j){
            child[j]+=cookies[i];
            rec(cookies, child, i+1, k, n);
            child[j]-=cookies[i];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        rec(cookies, child, 0, k, cookies.size());
        return ans;
    }
};