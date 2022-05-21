class Solution {
public:
    vector<int> par;
    
    int absParentMaker(int i){
        return par[i-97]<0?i:par[i-97]=absParentMaker(par[i-97]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size(), i;
        vector<int> t(26, -1);
        par = t;
        for(i=0;i<n;++i){
            int a = equations[i][1];
            int b = equations[i][2];
            
            if(a==b){
                int p1 = absParentMaker(equations[i][0]);
                int p2 = absParentMaker(equations[i][3]);
                
                if(p1!=p2){
                    par[p1-97] = p2;
                }
            }
        }
        for(i=0;i<n;++i){
            int a = equations[i][1];
            int b = equations[i][2];
            
            if(a!=b){
                int p1 = absParentMaker(equations[i][0]);
                int p2 = absParentMaker(equations[i][3]);
                
                if(p1==-1){
                    p1=equations[i][0];
                }
                if(p2==-1){
                    p2=equations[i][3];
                }
                
                // cout << char(p1) << " " << char(p2) << endl;
                
                if(p1==p2){
                    return false;
                }
                
                
            }
        }
        return true;
    }
};