class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x: stones){
            pq.push(x);
        }
        
        while(pq.size()>1){
            int f, s;
            f=pq.top();
            pq.pop();
            s=pq.top();
            pq.pop();
            if(f!=s){
                pq.push(abs(f-s));
            }
        }
        
        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};