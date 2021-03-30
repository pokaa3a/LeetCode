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
    int minOperations(int n)
    {
        if (n & 1)
        {
            int x = (n - 1) / 2;
            return (2 * x + 2) * x / 2;
        }
        else
        {
            int x = n / 2;
            return 2 * x * x / 2;
        }
    }
};

int main()
{
    Solution sol;

    int n = 3;
    cout << sol.minOperations(n) << endl;
}
