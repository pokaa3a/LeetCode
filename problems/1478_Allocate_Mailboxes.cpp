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
    int minDistance(vector<int>& houses, int K)
    {
        sort(houses.begin(), houses.end());
        
        int n = houses.size();
        vector<vector<int>> presum(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int med = (i + j) / 2;
                for (int k = i; k <= j; ++k)
                {
                    presum[i][j] += abs(houses[k] - houses[med]);
                }
            }
        }

        vector<vector<int>> dp(K + 1, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i)
        {
            dp[1][i] = presum[0][i];
        }

        for (int k = 2; k <= K; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i == 0)
                {
                    dp[k][0] = 0;
                    continue;
                }
                for (int j = 0; j <= i; ++j)
                {
                    dp[k][i] = min(dp[k][i], (j == 0 ? 0 : dp[k - 1][j - 1]) + presum[j][i]);
                }
                // cout << "dp[" << k << "][" << i << "] = " << dp[k][i] << endl;
            }
        }
        return dp[K][n - 1];
    }
};

int main()
{
    Solution sol;

    vector<int> houses = {1,4,8,10,20};
    int k = 3;

    // vector<int> houses = {2,3,5,12,18};
    // int k = 2;

    // vector<int> houses = {7,4,6,1};
    // int k = 1;

    // vector<int> houses = {3,6,14,10};
    // int k = 4;

    cout << sol.minDistance(houses, k) << endl;
}
