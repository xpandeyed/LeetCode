class Solution {
public:
    
    int help(vector<int>& chalk, int k){
        long long int sum=0;
        for(int x: chalk){
            sum+=x;
        }
        k%=sum;
        return k;
    }
    
    int rec(vector<int>& chalk, int k, int i=0){
        if(i>=chalk.size()){
            return rec(chalk, k);
        }
        if(chalk[i]>k){
            return i;
        }
        return rec(chalk, k-chalk[i], i+1);
        
    }
    
    int chalkReplacer(vector<int>& chalk, int k, int i=0) {
        k=help(chalk, k);
        return rec(chalk, k);
    }
};