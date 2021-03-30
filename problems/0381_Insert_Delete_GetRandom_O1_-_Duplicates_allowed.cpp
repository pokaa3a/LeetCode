#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> hash;
    vector<int> data;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool output = hash.find(val) == hash.end();

        hash[val].insert(data.size());
        data.push_back(val);

        return output;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) == hash.end()) return false;

        int idx = *hash[val].begin();
        hash[val].erase(idx);
        if (hash[val].size() == 0) hash.erase(val);

        if (idx == data.size() - 1)
        {
            if (idx != 0)
            {
                int swapVal = data[idx - 1];
                data[idx] = data[idx - 1];

                hash[swapVal].erase(idx - 1);
                hash[swapVal].insert(idx);
            }
        }
        else
        {
            int swapVal = data.back();
            data[idx] = data.back();

            hash[swapVal].erase(data.size() - 1);
            hash[swapVal].insert(idx);
        }
        data.pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};

int main()
{
    RandomizedCollection collection;
    cout << collection.insert(0) << endl;
    cout << collection.insert(1) << endl;
    cout << collection.remove(0) << endl;
    cout << collection.insert(2) << endl;
    cout << collection.remove(1) << endl;
    cout << collection.getRandom() << endl;
}
