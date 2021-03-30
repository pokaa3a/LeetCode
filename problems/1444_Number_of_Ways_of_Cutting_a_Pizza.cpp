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
typedef long long ll;
class Solution
{
public:
    int ways(vector<string>& pizza, int k)
    {
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>> presum(m, vector<int>(n, 0));
        for (int r = m - 1; r >= 0; --r)
        {
            for (int c = n - 1; c >= 0; --c)
            {
                presum[r][c] = (pizza[r][c] == 'A' ? 1 : 0)
                                + (r + 1 > m - 1 ? 0 : presum[r + 1][c])
                                + (c + 1 > n - 1 ? 0 : presum[r][c + 1])
                                - (r + 1 > m - 1 || c + 1 > n - 1 ? 0 : presum[r + 1][c + 1]);
            }
        }

        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(k, -1)));
        return dfs(presum, dp, 0, 0, k - 1);
    }

    ll dfs(vector<vector<int>>& presum, vector<vector<vector<ll>>>& dp, int r0, int c0, int cuts)
    {
        if (dp[r0][c0][cuts] != -1) return dp[r0][c0][cuts];
        if (cuts == 0 && presum[r0][c0] > 0) return 1;
        if (presum[r0][c0] == 0) return 0;

        int m = presum.size();
        int n = presum[0].size();

        ll ans = 0;
        for (int r = r0 + 1; r < m; ++r)
        {
            if (presum[r0][c0] > presum[r][c0] && presum[r][c0] > 0)
            {
                ans = (ans + dfs(presum, dp, r, c0, cuts - 1)) % MOD;
            }
        }

        for (int c = c0 + 1; c < n; ++c)
        {
            if (presum[r0][c0] > presum[r0][c] && presum[r0][c] > 0)
            {
                ans = (ans + dfs(presum, dp, r0, c, cuts - 1)) % MOD;
            }
        }

        dp[r0][c0][cuts] = ans % MOD;
        return dp[r0][c0][cuts];
    }
};

int main()
{
    Solution sol;

    // vector<string> pizza = {"A..", "AAA", "..."};
    // int k = 3;

    // vector<string> pizza = {"A..", "AA.", "..."};
    // int k = 3;

    // vector<string> pizza = {"A..", "A..", "..."};
    // int k = 1;

    vector<string> pizza = {".A..A",
                            "A.A..",
                            "A.AA.",
                            "AAAA.",
                            "A.AA."};
    

    int k = 5;

    cout << sol.ways(pizza, k) << endl;
}
