class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        int pn;
        while(n>0){
            pn = min(26, k-(n-1));
            // cout << pn << endl;
            k-=(pn);
            res+=(pn+'a'-1);
            n--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};