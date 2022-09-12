class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, maxScore=0, n=tokens.size(), s=0, l=n-1;
        sort(tokens.begin(), tokens.end());
        
        while(s<=l){
            if(power>=tokens[s]){
                power-=tokens[s];
                score++;
                maxScore=max(score, maxScore);
                s++;
            }else{
                if(score==0) return maxScore;
                score--;
                power+=tokens[l];
                l--;
                maxScore = max(maxScore, score);
            }
        }
        return maxScore;
        
    }
};