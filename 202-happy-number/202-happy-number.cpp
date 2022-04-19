class Solution {
public:
    bool rec(int n, set<int> &s){
        if(n==1){
            return true;
        }
        int sum = 0;
        queue<int> q;
        while(n>0){
            q.push(n%10);
            n/=10;
        }
        while(!q.empty()){
            sum+=(q.front()*q.front());
            q.pop();
        }
        if(s.find(sum)!=s.end()){
            // cout << sum << endl;
            return false;
        }
        s.insert(sum);
        return rec(sum, s);
        
    }
    
    bool isHappy(int n) {
        set<int> s;
        return rec(n, s);
    }
};