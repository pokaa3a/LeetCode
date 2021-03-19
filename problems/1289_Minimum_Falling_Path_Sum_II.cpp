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
// https://leetcode.com/problems/minimum-falling-path-sum-ii/
const int MOD = 1000000007;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr)
    {
        int n = arr.size();

        // sum[r][0] == smallest sum in rth row, sum[r][1] == second smallest sum in rth row
        // pari.first: row, pair.second: sum
        vector<vector<pair<int, int>>> sum(n, vector<pair<int, int>>(2, make_pair(INT_MAX, INT_MAX)));

        int ans = INT_MAX;
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int newSum = arr[r][c];
                if (r > 0)
                {
                    if (sum[r - 1][0].first != c)
                    {
                        newSum = sum[r - 1][0].second + arr[r][c];
                    }
                    else
                    {
                        newSum = sum[r - 1][1].second + arr[r][c];
                    }
                }
                
                // Update smallest sums
                if (newSum < sum[r][0].second)
                {
                    sum[r][1] = sum[r][0];
                    sum[r][0] = make_pair(c, newSum);
                }
                else if (newSum >= sum[r][0].second && newSum < sum[r][1].second)
                {
                    sum[r][1] = make_pair(c, newSum);
                }

                if (r == n - 1)
                {
                    ans = min(ans, sum[r][0].second);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    // vector<vector<int>> arr = {{-73,61,43,-48,-36},
    //                            {3,30,27,57,10},
    //                            {96,-76,84,59,-15},
    //                            {5,-49,76,31,-7},
    //                            {97,91,61,-46,67}};

    cout << sol.minFallingPathSum(arr) << endl;
}
