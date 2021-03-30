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
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q)
    {
        unordered_set<int> path;

        Node* cur = p;
        while (cur)
        {
            path.insert(cur->val);
            cur = cur->parent;
        }
        cur = q;
        while (cur)
        {
            if (path.count(cur->val) > 0) return cur;
            cur = cur->parent;
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
}
