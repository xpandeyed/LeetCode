class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size(), last, ri, di, a, b, c;
        di=n-1;
        last=days[n-1];
        vector<int> res(410, 0);
        for(ri=last; ri>=days[0]; --ri){
            if(ri!=days[di]){
                res[ri]=res[ri+1];
                continue;
            }
            a = costs[0] +res[ri+1];
            b = costs[1] +res[ri+7];
            c = costs[2] +res[ri+30];
            res[ri]=min(a, min(b, c));
            di--;
        }
        
        return res[days[0]];
    }
};