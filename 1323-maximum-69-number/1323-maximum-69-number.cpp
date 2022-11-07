class Solution {
public:
    int maximum69Number (int num) {
        string t = to_string(num);
        for(int i=0;i<t.size();++i){
            if(t[i]=='6'){
                t[i]='9';
                num = stoi(t);
                return num;
            }
        }
        return num;
    }
};