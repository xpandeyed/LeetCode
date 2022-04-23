class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size(), n2 = needle.size(), pat=0, str=0, i, j, flag=1;
        if(n2==0){
            return 0;
        }
        for(i=0; i<n2; ++i){
            pat+=needle[i];
            str+=haystack[i];
            if(needle[i]!=haystack[i]){
                flag=0;
            }
        }
        if(flag){
            return 0;
        }
        for(i=n2; i<n1; ++i){
            str-=(haystack[i-n2]);
            str+=haystack[i];
            if(str==pat){
                bool check = true;
                for(j=0; j<n2; ++j){
                    if(needle[j]!=haystack[i-n2+1+j]){
                        check = false;
                    }
                }
                if(check){
                    return i-n2+1;
                }
            }
        }
        return -1;
    }
};