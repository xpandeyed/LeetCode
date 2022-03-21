class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, lastOcc(26, -1);
        int n=s.size(), i, l, j;
        for(i=0; i<n; ++i){
            lastOcc[s[i]-'a']=i;
        }
        
        // for(auto x: lastOcc){
        //     cout << x << " ";
        // }
        // cout << endl;
        
        i=0;
        while(i<n){
            // cout << "i " << i << endl; 
            l=lastOcc[s[i]-'a'];
            // cout << "l " << l << endl;
            j=i+1;
            // cout << "j " << j << endl;
            while(j<=l){
                l=max(l, lastOcc[s[j]-'a']);
                // cout << "l " << l << endl;
                j++;
                // cout << "j " << j << endl;
            }
            res.push_back(l-i+1);
            i=l+1;
        }
        
        return res;
        
    }
};