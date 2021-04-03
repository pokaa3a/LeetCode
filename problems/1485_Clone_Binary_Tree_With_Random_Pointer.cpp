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
    unordered_map<Node*, NodeCopy*> mp;
public:
    NodeCopy* copyRandomBinaryTree(Node* root)
    {
        if (!root) return nullptr;
        if (mp.find(root) != mp.end()) return mp[root];

        NodeCopy* newNode = new NodeCopy(root->val);
        mp[root] = newNode;
        newNode->left = copyRandomBinaryTree(root->left);
        newNode->right = copyRandomBinaryTree(root->right);
        newNode->random = copyRandomBinaryTree(root->random);

        return newNode;
    }
};

int main()
{
    Solution sol;
}
