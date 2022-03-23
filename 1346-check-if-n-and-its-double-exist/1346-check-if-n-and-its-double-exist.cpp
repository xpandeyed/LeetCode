class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(int x: arr){
            if(s.find(x*2)!=s.end()){
                return true;
            }
            if(x%2==0 and s.find(x/2)!=s.end()){
                return true;
            }
            s.insert(x);
        }
        
        return false;
    }
};