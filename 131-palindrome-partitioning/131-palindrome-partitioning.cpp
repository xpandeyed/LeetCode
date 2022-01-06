class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void func(vector<vector<string>> &res, vector<string> &path, int index, string s){
        if(index==s.size()){
            res.push_back(path);
            return ;
        }
        for(int i=index; i<s.size(); ++i){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                func(res, path, i+1, s);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(res, path, 0, s);
        return res;
    }
};