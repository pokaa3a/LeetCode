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
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 1)
                {
                    row[r]++;
                    col[c]++;
                }
            }
        }

        int ans = 0;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 1)
                {
                    ans += row[r] > 1 || col[c] > 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> grid = {{1, 0}, {1, 1}};
    vector<vector<int>> grid = {{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};

    cout << sol.countServers(grid) << endl;
}
