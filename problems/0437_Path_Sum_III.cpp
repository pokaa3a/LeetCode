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
    int pathSum(TreeNode* root, int targetSum)
    {
        int ans = 0;
        unordered_map<int, int> presum;
        presum[0] = 1;

        helper(root, 0, targetSum, ans, presum);
        
        return ans;
    }

    void helper(TreeNode* root, int sum, int target, int& ans, unordered_map<int, int>& presum)
    {
        if (!root) return;

        sum += root->val;

        if (presum.find(sum - target) != presum.end()) ans += presum[sum - target];

        presum[sum]++;
        
        helper(root->left, sum, target, ans, presum);
        helper(root->right, sum, target, ans, presum);

        if (--presum[sum] == 0) presum.erase(sum);
    }
};

int main()
{
    Solution sol;
}
