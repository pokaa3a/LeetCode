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
    vector<int> pathsWithMaxScore(vector<string>& board)
    {
        int n = board.size();

        // pair.first == max sum, pair.second == num of paths
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, make_pair(0, 0)));

        // from bottom-right to top-left == from top-left to bottom-right
        dp[0][0] = make_pair(0, 1);

        int r_step[3] = {-1, 0, -1};
        int c_step[3] = {0, -1, -1};

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (r == 0 && c == 0) continue;
                if (board[r][c] == 'X') continue;

                long long sum = 0;
                long long num = 0;
                for (int k = 0; k < 3; ++k)
                {
                    int r_prev = r + r_step[k];
                    int c_prev = c + c_step[k];

                    if (r_prev >= 0 && c_prev >= 0 && dp[r_prev][c_prev].second != 0)
                    {
                        long long newSum = dp[r_prev][c_prev].first + (r == n - 1 && c == n - 1 ? 0 : board[r][c] - '0');
                        if (newSum > sum)
                        {
                            sum = newSum;
                            num = dp[r_prev][c_prev].second;
                        }
                        else if (newSum == sum)
                        {
                            num = (num + dp[r_prev][c_prev].second) % MOD;
                        }
                    }
                }
                dp[r][c] = make_pair(sum, num);
                // cout << "(r,c) = (" << r << ", " << c << ") = " << sum << ", " << num << endl;
            }
        }
        return vector<int>{dp[n - 1][n - 1].first, dp[n - 1][n - 1].second};
    }
};

int main()
{
    Solution sol;

    // vector<string> board = {"E23", "2X2", "12S"};    // 7, 1
    // vector<string> board = {"E12","1X1","21S"};      // 4, 2
    // vector<string> board = {"E11","XXX","11S"};      // 0, 0
    vector<string> board = {"E11345","X452XX","3X43X4","422812","284522","13422S"};  // 34, 3

    vector<int> ans = sol.pathsWithMaxScore(board);
    cout << ans[0] << ", " << ans[1] << endl;
}
