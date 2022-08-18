class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        int n=arr.size();
        for(auto x: arr){
            m[x]++;
        }
        priority_queue<int> q;
        for(auto [key, val]: m){
            q.push(val);
        }
        int res = 0, ele = 0;
        while(!q.empty() and ele<n/2){
            // cout << ele << " : " << q.top() << endl;
            ele+=q.top();
            res++;
            q.pop();
        }
        return res;
        
    }
};