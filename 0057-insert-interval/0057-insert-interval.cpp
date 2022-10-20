class Solution {
public:
    
    
    vector<vector<int>> insert(vector<vector<int>>& invs, vector<int>& ni) {
        invs.push_back(ni);
        sort(invs.begin(), invs.end());
        vector<vector<int>> res;
        res.push_back(invs[0]);
        int s=1;
        for(int i=1;i<invs.size();++i){
            // cout << i << endl;
            int endofprev=res[s-1][1];
            if(endofprev<invs[i][0]){
                res.push_back(invs[i]);
                s++;
                continue;
            }
            res[s-1][0]=min(res[s-1][0], invs[i][0]);
            res[s-1][1]=max(res[s-1][1], invs[i][1]);
        }
        return res;
    }
};

//non overlapping situations
//start of curr is greater than end of prev

//find position
//1prev interval's end is less and next interval's start is greater
//OR
//2prev interval's end lies in between
//OR
//3next interval's start lies in between
//put ni after the interval found