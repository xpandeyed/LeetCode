class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res=0, i=0, d, n=events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(d=1;d<=100000;++d){
            while(!pq.empty() and pq.top()<d)
                pq.pop();
            while(i<n and events[i][0]==d)
                pq.push(events[i++][1]);
            if(!pq.empty()){
                res++;
                pq.pop();
            }
        }
        return res;
    }
};