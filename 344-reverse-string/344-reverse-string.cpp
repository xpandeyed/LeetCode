class Solution {
public:
    void helper(vector<char>& s, int l, int h){
        if(l>h){
            return ;
        }
        swap(s[l], s[h]);
        helper(s, l+1, h-1);
    }
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }
};