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
private:
    vector<NestedInteger> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1; i>=0; i--){
            list.push_back(nestedList[i]);
        }
    }

    int next() {
        NestedInteger i = list.back();
        list.pop_back();
        return i.getInteger();
    }

    bool hasNext() {
        while(!list.empty()){
            NestedInteger p = list.back();
            if(p.isInteger()) return true;
            
            list.pop_back();
            vector<NestedInteger> &nList = p.getList();
            for(int i=nList.size()-1; i>=0; i--){
                list.push_back(nList[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */