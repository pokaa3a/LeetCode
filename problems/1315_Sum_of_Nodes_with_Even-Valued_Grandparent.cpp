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
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
const int MOD = 1000000007;
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root)
    {
        int ans = 0;
        if (!root) return root;
        
        dfs(root->left, false, root->val % 2 == 0, ans);
        dfs(root->right, false, root->val % 2 == 0, ans);
        return ans;
    }

    void dfs(TreeNode* node, bool evenGrandParents, bool evenParents, int& ans)
    {
        if (!node) return;

        if (evenGrandParents) ans += node->val;

        dfs(node->left, evenParents, node->val % 2 == 0, ans);
        dfs(node->right, evenParents, node->val % 2 == 0, ans);
    }
};

int main()
{
    Solution sol;
}
