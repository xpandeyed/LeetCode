class Solution {
public:
    void reverser(string &s, int start, int end){
        while(start<end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    
    string reverseWords(string s) {
        int n=s.size(), i, start=0, end;
        for(i=0; i<=n; ++i){
            if(i==n || s[i]==' '){
                end=i-1;
                reverser(s, start, end);
                start =end+2;
            }
        }
        
        return s;
    }
};