class Solution {
public:
    int minOperations(string s) {
        string s1 = "", s2 = "";
        int n = s.size();
        for(int i=1; i<=n; ++i){
            if(i%2==0){
                s1+='0';
                s2+='1';
            }else{
                s1+='1';
                s2+='0';
            }
        }
        int count1 =0, count2 = 0;
        for(int i=0; i<n; ++i){
            if(s[i]!=s1[i]){
                count1++;
            }
            if(s[i]!=s2[i]){
                count2++;
            }
        }
        return min(count1, count2);
    }
};