class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size(), mi=salary[0], ma = salary[0], i;
        double res=0;
        for(i=0; i<n; ++i){
            res+=salary[i];
            if(mi>salary[i]){
                mi=salary[i];
            }
            if(ma<salary[i]){
                ma=salary[i];
            }
        }
        
        res-=mi;
        res-=ma;
        
        res/=(n-2);
        
        return res;
    }
};