class Solution {
public:
    vector<string> s;
    int n, res=0;
    
    bool check(string s1, string s2){
        unordered_set<char> t1, t2;
        for(auto x: s1){
            if(t1.find(x)!=t1.end()) return false;
            t1.insert(x);
        }
        for(auto x: s2){
            if(t2.find(x)!=t2.end() or t1.find(x)!=t1.end()) return false;
            t2.insert(x);
        }
        return true;
    }
    
    void rec(int i, string curr){
        if(i==n){
            int si = curr.size();
            res=max(res, si);
            return ;
        }
        //proceed without accepting current string
        rec(i+1, curr);
        //check if s[i] can be accepted or not
        if(check(curr, s[i])){
            curr+=s[i];
            rec(i+1, curr);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        s=arr;
        n=arr.size();
        rec(0, "");
        return res;
    }
};