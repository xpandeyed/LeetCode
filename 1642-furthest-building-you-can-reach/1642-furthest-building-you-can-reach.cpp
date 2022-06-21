class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //the idea is simple we replace maximum use of bricks with one ladder
        priority_queue<int>pq;
        for(int i=1;i<heights.size();i++)
        {
            int diff= heights[i]-heights[i-1];
            if(diff<=0)continue;
            
            
            bricks-=diff;
            pq.push(diff);
            if(bricks<0)
            {
                ladders--;
                bricks+=pq.top();
                pq.pop();
                if(ladders<0 or bricks<0)
                    return i-1;
            }
        }
        return heights.size()-1;   //reached last :)
    }
};