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
    Node* inorderSuccessor(Node* node)
    {
        if (!node) return nullptr;

        if (node->right)
        {
            Node* cur = node->right;
            while (cur->left)
            {
                cur = cur->left;
            }
            return cur;
        }
        else if (node->parent)
        {
            Node* cur = node;
            while (cur->parent)
            {
                if (cur->parent->val > node->val) return cur->parent;
                cur = cur->parent;
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
}
