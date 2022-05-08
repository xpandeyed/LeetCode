/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> l;
    int i=-1;
    int s;
    
    void finishList(vector<NestedInteger> nestedList, int i, int n){
        if(i>=n){
            return ;
        }
        if(nestedList[i].isInteger()){
            l.push_back(nestedList[i].getInteger());
            finishList(nestedList, i+1, n);
        }else{
            vector<NestedInteger> tempList = nestedList[i].getList();
            finishList(tempList, 0, tempList.size());
            finishList(nestedList, i+1, n);
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n=nestedList.size();
        finishList(nestedList, 0, n);
        i=-1;
        s=l.size();
        // for(int k: l){
        //     cout << k << " ";
        // }
    }
    
    int next() {
        return l[++i];
    }
    
    bool hasNext() {
        if(i<s-1){
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */