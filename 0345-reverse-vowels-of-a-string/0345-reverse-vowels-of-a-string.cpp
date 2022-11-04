class Solution {
public:
    string reverseVowels(string s) {
        string v = "";
        for(auto x: s){
            if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U') v+=x;
        }
        reverse(v.begin(), v.end());
        int i=0;
        for(int j=0;j<s.size();++j){
            if(s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u' or s[j]=='A' or s[j]=='E' or s[j]=='I' or s[j]=='O' or s[j]=='U'){
                s[j]=v[i];
                i++;
            }
        }
        return s;
    }
};