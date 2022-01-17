class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<char> pat;
        vector<string> str;
        int n1=pattern.size(), n2=s.size(), i=0, j;
        string temp="";
        for(j=0; j<n2; ++j){
            if(s[j]==' '){
                int i1, i2 ;
                i1 = find(pat.begin(), pat.end(), pattern[i])-pat.begin();
                i2 = find(str.begin(), str.end(), temp) - str.begin();
                if(i1==i2){
                    if(i1==pat.size()){
                        pat.push_back(pattern[i]);
                        str.push_back(temp);
                        
                    }
                    temp="";
                    i++;
                    
                }else{
                    return false;
                }
            }
            else{
                temp+=s[j];
            }
        }
         int i1, i2 ;
                i1 = find(pat.begin(), pat.end(), pattern[i])-pat.begin();
                i2 = find(str.begin(), str.end(), temp) - str.begin();
        cout << i1 << " " << pattern[i] << i2 << " " << temp ;
                if(i1==i2){
                    if(i1==pat.size()){
                        pat.push_back(pattern[i]);
                        str.push_back(temp);
                        temp="";
                    }
                    
                }else{
                    return false;
                }
        
        if(i==n1-1){
            return true;
        }
        return false;
    }
};