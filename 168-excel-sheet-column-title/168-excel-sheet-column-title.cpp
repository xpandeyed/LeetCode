class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while(n>0){
            int temp = n%26;
            if(temp==0){
                res+='Z';
                n/=26;
                n--;
            }else{
                res+=(temp-1+'A');
                n/=26;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};