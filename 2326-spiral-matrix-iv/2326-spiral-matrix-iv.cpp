class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int sr=0, sc=0, er=m-1, ec=n-1, i;
        
        while(head!=NULL){
            for(i=sc; i<=ec and head!=NULL; ++i){
                res[sr][i]=head->val;
                head=head->next;
            }
            sr++;
            for(i=sr;i<=er and head!=NULL; ++i){
                res[i][ec]=head->val;
                head=head->next;
            }
            ec--;
            for(i=ec;i>=sc and head!=NULL; --i){
                res[er][i]=head->val;
                head=head->next;
            }
            er--;
            for(i=er;i>=sr and head!=NULL; --i){
                res[i][sc]=head->val;
                head=head->next;
            }
            sc++;
        }
        return res;
    }
};