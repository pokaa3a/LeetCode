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
    int countPairs(TreeNode* root, int distance)
    {
        vector<int> count(11, 0);   // count[i] = k -> k pairs have distance i
        unordered_map<int, int> mp;
        countDistance(root, distance, mp, count);
        return accumulate(count.begin(), count.end(), 0);
    }

    void countDistance(TreeNode* root, int distance, unordered_map<int, int>& mp, vector<int>& count)
    {
        if (!root->left && !root->right)
        {
            mp[0] = 1;
            return;
        }

        unordered_map<int, int> mpLeft, mpRight;
        if (root->left) countDistance(root->left, distance, mpLeft, count);
        if (root->right) countDistance(root->right, distance, mpRight, count);

        for (auto l : mpLeft)
        {
            for (auto r : mpRight)
            {
                int dist = l.first + 1 + r.first + 1;
                if (dist <= distance)
                {
                    count[dist] += l.second * r.second;
                }
            }
        }

        for (auto l : mpLeft) mp[l.first + 1] += l.second;
        for (auto r : mpRight) mp[r.first + 1] += r.second;
    }
};

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    int distance = 3;

    Solution sol;
    cout << sol.countPairs(n1, distance);
}
