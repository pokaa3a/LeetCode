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
// https://leetcode.com/problems/paint-house-iii/
const int MOD = 1000000007;
class Solution {
private:
    const int maxCost = 10000 * 100 + 1;
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        // dp[m][g][c] = min cost of first 'm + 1' houses, with 'g' groups and 'c' cost
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1 , maxCost)));

        for (int i = 0; i < m; ++i)
        {
            for (int g = 1; g <= target; ++g)
            {
                if (g > i + 1) continue;

                for (int c = 1; c <= n; ++c)
                {
                    if (houses[i] == 0)     // not painted
                    {
                        // first house
                        if (i == 0)
                        {
                            dp[i][g][c] = cost[i][c - 1];
                            continue;
                        }
                        
                        for (int cPrev = 1; cPrev <= n; ++cPrev)
                        {
                            if (cPrev == c) // not adding new group
                            {
                                dp[i][g][c] = min(dp[i][g][c], dp[i - 1][g][cPrev] + cost[i][c - 1]);
                            }
                            else            // adding new group
                            {
                                dp[i][g][c] = min(dp[i][g][c], dp[i - 1][g - 1][cPrev] + cost[i][c - 1]);
                            }
                        }
                    }
                    else                    // painted
                    {
                        if (houses[i] == c)
                        {
                            // fist house
                            if (i == 0)
                            {
                                dp[i][g][c] = 0;
                                continue;
                            }

                            for (int cPrev = 1; cPrev <= n; ++cPrev)
                            {
                                if (cPrev == c)     // not adding new group
                                {
                                    dp[i][g][c] = min(dp[i][g][c], dp[i - 1][g][cPrev]);
                                }
                                else                // adding new group
                                {
                                    dp[i][g][c] = min(dp[i][g][c], dp[i - 1][g - 1][cPrev]);
                                }
                            }
                        }
                        else
                        {
                            dp[i][g][c] = maxCost;
                        }
                    }
                }
            }
        }

        int ans = maxCost;
        for (int c = 1; c <= n; c++)
        {
            ans = min(ans, dp[m - 1][target][c]);
        }
        
        return ans >= maxCost ? -1 : ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> houses = {0,0,0,0,0};
    // vector<vector<int>> cost = {{1,10}, {10,1}, {10,1}, {1,10}, {5,1}};
    // int m = 5, n = 2, target = 3;

    // vector<int> houses = {0,2,1,2,0};
    // vector<vector<int>> cost = {{1,10}, {10,1}, {10,1}, {1,10}, {5,1}};
    // int m = 5, n = 2, target = 3;

    // vector<int> houses = {0,0,0,0,0};
    // vector<vector<int>> cost = {{1,10}, {10,1}, {1,10}, {10,1}, {1,10}};
    // int m = 5, n = 2, target = 5;

    vector<int> houses = {3,1,2,3};
    vector<vector<int>> cost = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
    int m = 4, n = 3, target = 3;

    cout << sol.minCost(houses, cost, m, n, target) << endl;
}
