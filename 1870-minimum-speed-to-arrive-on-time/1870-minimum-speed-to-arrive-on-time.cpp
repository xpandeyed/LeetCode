class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long int n=dist.size(), i, res=INT_MAX, l=1, h=INT_MAX, m;
        double time;
        while(l<=h){
            m=(l+h)/2;
            time = 0;
            for(int x: dist){
                time=ceil(time);
                time+=((double)x/double(m));
            }
            // cout << m<< " " << time << endl;
            if(time>hour){
                l=m+1;
            }else{
                res=min(m, res);
                h=m-1;
            }
        }
        if(res>1000000000){
            return -1;
        }
        return res;
    }
};