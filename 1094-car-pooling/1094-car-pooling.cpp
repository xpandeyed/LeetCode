class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        bool res=true;
        vector<int> pass(1002, 0);
        int n = trips.size();
        for(int i=0; i<n ; ++i){
            pass[trips[i][1]]+=trips[i][0];
            pass[trips[i][2]]-=trips[i][0];
        }
        if(pass[0]>capacity){
            return false;
        }
        for(int i=1; i<1002; ++i){
            pass[i]+=pass[i-1];
            if(pass[i]>capacity){
                return false;
            }
        }
        return true;
    }
};