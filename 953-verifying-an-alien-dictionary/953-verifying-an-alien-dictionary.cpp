class Solution {
public:    
    //for no swap return true
    // vector<int> pos;
    
    // static bool mySort(string &s1, string &s2){
    //     int n1=s1.size(), n2=s2.size(), i=0, j=0;
    //     while(i<n1 and j<n2){
    //         if(pos[s1[i]-97]<pos[s2[j]-97]){
    //             return true;
    //         }else if(pos[s1[i]-97]>pos[s2[j]-97]){
    //             return false;
    //         }
    //         i++;
    //         j++;
    //     }
    //     if(n1<n2){
    //         return true;
    //     }
    //     return false;
    // }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26, -1);
        for(int i=0;i<26; ++i){
            pos[order[i]-97]=i;
        }
        
        vector<string> temp = words;
        sort(temp.begin(), temp.end(), [&](string s1, string s2){
                    int n1=s1.size(), n2=s2.size(), i=0, j=0;
        while(i<n1 and j<n2){
            if(pos[s1[i]-97]<pos[s2[j]-97]){
                return true;
            }else if(pos[s1[i]-97]>pos[s2[j]-97]){
                return false;
            }
            i++;
            j++;
        }
        if(n1<n2){
            return true;
        }
        return false;
        });
        int n=words.size(), i;
        for(i=0;i<n;++i){
            if(words[i]!=temp[i]){
                return false;
            }
        }
        
        return true;
    }
};