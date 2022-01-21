class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), currFuel = 0, prevFuel = 0, i, start=0;
        for(i=0; i<n ; ++i){
            currFuel += (gas[i]-cost[i]);
            if(currFuel<0){
                start=i+1;
                prevFuel+=currFuel;
                currFuel=0;
            }
        }
        if(currFuel+prevFuel>=0){
            return start;
        }
        return -1;
    }
};