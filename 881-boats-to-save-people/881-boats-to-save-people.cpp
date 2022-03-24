class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size(), start=0, end=n-1, boats=0;
        sort(people.begin(), people.end(), greater<int>());
        while(start<=end){
            if(people[start]+people[end]<=limit){
                start++;
                end--;
            }else{
                start++;
            }
            boats++;
        }
        
        return boats;
    }
};