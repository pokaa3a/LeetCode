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
// https://leetcode.com/problems/the-kth-factor-of-n/
class Solution {
public:
    int kthFactor(int n, int k)
    {
        int count = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
            {
                count++;
                if (count == k) return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int n = 1000, k = 3;
    cout << sol.kthFactor(n, k) << endl;
}
