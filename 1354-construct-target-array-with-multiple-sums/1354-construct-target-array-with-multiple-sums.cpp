class Solution {
public:
    //if max element from array <= sum of remaining elements return false
    //if max element in array is 1 return true
    bool isPossible(vector<int>& target) {
        long long int n=(long long int)target.size(), i, sum=0;
        priority_queue<long long int> q;
        for(i=0;i<n;++i){
            sum+=target[i];
            q.push((long long int)target[i]);
        }
        while(true){
            long long int curr = q.top();
            q.pop();
            if(curr==1){
                return true;
            }
            sum-=curr;
            // cout << sum << " " << curr << endl;
            if(sum>=curr or !sum){
                return false;
            }
            if(sum!=1 and curr%sum==0){
                return false;
            }
            curr%=sum;
            sum+=curr;
            q.push(curr);
        }
        return true;
    }
};
// 1 1 10
// 1 1 0
