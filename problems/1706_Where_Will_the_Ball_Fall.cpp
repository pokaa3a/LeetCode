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
// https://leetcode.com/problems/where-will-the-ball-fall/
const int MOD = 1000000007;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        int cols = grid[0].size();
        vector<int> ans(cols);
        for (int c = 0; c < cols; ++c)
        {
            ans[c] = findSingleBall(c, grid);
        }
        return ans;
    }
    int findSingleBall(int start, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int c = start;
        for (int r = 0; r < m; ++r)
        {
            if (grid[r][c] == 1)
            {
                if (c + 1 == n) return -1;
                if (grid[r][c + 1] == -1) return -1;
                c++;
            }
            else
            {
                if (c - 1 < 0) return -1;
                if (grid[r][c - 1] == 1) return -1;
                c--; 
            }
        }
        return c;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> grid = {{1,   1,  1, -1, -1},
    //                             {1,   1,  1, -1, -1},
    //                             {-1, -1, -1,  1,   1},
    //                             {1,   1,  1,  1, -1},
    //                             {-1, -1, -1, -1, -1}};
    vector<vector<int>> grid = {{1,1,1,1,1,1},
                                {-1,-1,-1,-1,-1,-1},
                                {1,1,1,1,1,1},
                                {-1,-1,-1,-1,-1,-1}};
    vector<int> box = sol.findBall(grid);

    for (int x: box)
    {
        cout << x << " ";
    }
}
