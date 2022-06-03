class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        vector<int> count(60, 0);
        for(int i=0;i<time.size(); ++i){
            int reminder = time[i]%60;
            int moreRequired = 60-reminder;
            if(moreRequired==60){
                result+=count[0];
            }else{
                result+=count[moreRequired];
            }
            count[reminder]++;
        }
        return result;
    }
};