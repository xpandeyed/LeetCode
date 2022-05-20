class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(), i, res=0, currCost, prevCost;
        stack<pair<int, int>> s;
        for(i=0;i<n;++i){
            if(!s.empty() and s.top().first==colors[i]){
                currCost=neededTime[i];
                prevCost=s.top().second;
                s.pop();
                res+=min(currCost, prevCost);
                s.push(make_pair(colors[i], max(currCost, prevCost)));
            }else{
                s.push(make_pair(colors[i], neededTime[i]));
            }
        }
        return res;
    }
};