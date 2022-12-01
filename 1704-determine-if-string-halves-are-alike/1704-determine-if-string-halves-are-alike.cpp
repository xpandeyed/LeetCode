class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size(), l=0, r=0, start=0, end=n-1;
        while(start<end){
            char cs = s[start], ce = s[end];
            if(cs=='a' or cs=='e' or cs=='i' or cs=='o' or cs=='u' or cs =='A' or cs=='E' or cs=='I' or cs=='O' or cs=='U') l++;
            if(ce=='a' or ce=='e' or ce=='i' or ce=='o' or ce=='u' or ce =='A' or ce=='E' or ce=='I' or ce=='O' or ce=='U') r++;
            start++;
            end--;
            
        }
        
        return l==r;
    }
};