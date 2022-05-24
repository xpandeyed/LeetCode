class Solution {
public:
    
    string customSortString(string order, string s) {
        vector<int> pos(26, -1);
        int n=order.size(), i;
        for(i=0;i<n;++i){
            pos[order[i]-97]=i;
        }
        // cout << "here" << endl;
        sort(s.begin(), s.end(), [&](char a, char b){
            // cout << a << " " << b << endl;
            if(pos[a-'a']>=pos[b-'a']){
                return false;
            }
            return true;
        });
        
        return s;
        
    }
};