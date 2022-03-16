class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n=pushed.size(), pu=0, po=0;
        while(pu<n and po<n){
            if(!s.empty() and s.top()==popped[po]){
                s.pop();
                po++;
            }else{
                s.push(pushed[pu]);
                pu++;
            }
        }
        
        while(!s.empty()){
            if(s.top()!=popped[po]){
                return false;
            }
            
            s.pop();
            po++;
        }
        
        return true;
    }
};