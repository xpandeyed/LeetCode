class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(), i;
        string curr="";
        vector<string> words;
        for(i=0;i<n;++i){
            if(s[i]==' '){
                if(curr!=""){
                    words.push_back(curr);
                }
                curr="";
            }
            else{
                curr+=s[i];
            }
        }
        if(curr!=""){
            words.push_back(curr);
        }
        reverse(words.begin(), words.end());
        curr="";
        n=words.size();
        for(i=0;i<n-1; ++i){
            curr+=words[i];
            curr+=" " ;
        }
        curr+=words[i];
        return curr;
    }
};