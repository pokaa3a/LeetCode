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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries)
    {
        vector<int> group(n + 1);
        for (int i = 1; i <= n; ++i) group[i] = i;

        for (int i = threshold + 1; i <= n; ++i)
        {
            for (int j = 2 * i; j <= n; ++j)
            {
                if (j % i == 0) uni(i, j, group);
            }
        }

        vector<bool> ans;
        for (auto q: queries)
        {
            if (find(q[0], group) == find(q[1], group)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }

    int find(int x, vector<int>& group)
    {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
    void uni(int x, int y, vector<int>& group)
    {
        int a = find(x, group);
        int b = find(y, group);
        if (a != b) group[a] = b;
    }
    int gcd(int a, int b)
    {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};

int main()
{
    Solution sol;

    int n = 6;
    int threshold = 2;
    vector<vector<int>> queries = {{1,4}, {2,5}, {3,6}};

    // int n = 6;
    // int threshold = 0;
    // vector<vector<int>> queries = {{4,5}, {3,4}, {3,2}, {2,6}, {1,3}};

    // int n = 5;
    // int threshold = 1;
    // vector<vector<int>> queries = {{4,5}, {4,5}, {3,2}, {2,3}, {3,4}};

    vector<bool> ans = sol.areConnected(n, threshold, queries);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
