class Solution {
public:
    int minNumberOfFrogs(string s) {
        vector<int> c(5,0);
        int i,n=s.size(), res=0, j;
        for(i=0;i<n;++i){
            if(s[i]=='c'){
                c[0]++;
            }else if(s[i]=='r'){
                c[1]++;
            }else if(s[i]=='o'){
                c[2]++;
            }else if(s[i]=='a'){
                c[3]++;
            }else if(s[i]=='k'){
                c[4]++;
            }else{
                return -1;
            }
            for(j=0;j<4;++j){
                if(c[j]<c[j+1]) return -1;
            }
            res = max(res, c[0]-c[4]);
        }
        for(i=0;i<4;++i){
            if(c[i]!=c[i+1]) return -1;
        }
        return res;
    }
};
//frequency order at any point c>=r>=o>=a>=k
//at any point number of frogs = c-k