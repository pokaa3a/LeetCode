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
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
const int MOD = 1000000007;
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return hasValidPathImpl(0, 0, grid, visited);
    }
    bool hasValidPathImpl(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (r == m - 1 && c == n - 1) return true;

        visited[r][c] = true;
        if (grid[r][c] == 1)
        {
            // left
            if (c - 1 >= 0 && !visited[r][c - 1] &&
                (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) &&
                hasValidPathImpl(r, c - 1, grid, visited)) return true;

            // right
            if (c + 1 < n  && !visited[r][c + 1] && 
                (grid[r][c + 1] == 1 || grid[r][c + 1] == 3 || grid[r][c + 1] == 5) &&
                hasValidPathImpl(r, c + 1, grid, visited)) return true;
        }
        else if (grid[r][c] == 2)
        {
            // up
            if (r - 1 >= 0 && !visited[r - 1][c] &&
                (grid[r - 1][c] == 2 || grid[r - 1][c] == 3 || grid[r - 1][c] == 4) &&
                hasValidPathImpl(r - 1, c, grid, visited)) return true;

            // down
            if (r + 1 < m  && !visited[r + 1][c] &&
                (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) &&
                hasValidPathImpl(r + 1, c, grid, visited)) return true;
        }
        else if (grid[r][c] == 3)
        {
            // left
            if (c - 1 >= 0 && !visited[r][c - 1] &&
                (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) &&
                hasValidPathImpl(r, c - 1, grid, visited)) return true;

            // down
            if (r + 1 < m  && !visited[r + 1][c] &&
                (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) &&
                hasValidPathImpl(r + 1, c, grid, visited)) return true;
        }
        else if (grid[r][c] == 4)
        {
            // right
            if (c + 1 < n  && !visited[r][c + 1] && 
                (grid[r][c + 1] == 1 || grid[r][c + 1] == 3 || grid[r][c + 1] == 5) &&
                hasValidPathImpl(r, c + 1, grid, visited)) return true;

            // down
            if (r + 1 < m  && !visited[r + 1][c] &&
                (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) &&
                hasValidPathImpl(r + 1, c, grid, visited)) return true;
        }
        else if (grid[r][c] == 5)
        {
            // up
            if (r - 1 >= 0 && !visited[r - 1][c] &&
                (grid[r - 1][c] == 2 || grid[r - 1][c] == 3 || grid[r - 1][c] == 4) &&
                hasValidPathImpl(r - 1, c, grid, visited)) return true;

            // left
            if (c - 1 >= 0 && !visited[r][c - 1] &&
                (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) &&
                hasValidPathImpl(r, c - 1, grid, visited)) return true;
        }
        else if (grid[r][c] == 6)
        {
            // up
            if (r - 1 >= 0 && !visited[r - 1][c] &&
                (grid[r - 1][c] == 2 || grid[r - 1][c] == 3 || grid[r - 1][c] == 4) &&
                hasValidPathImpl(r - 1, c, grid, visited)) return true;

            // right
            if (c + 1 < n  && !visited[r][c + 1] && 
                (grid[r][c + 1] == 1 || grid[r][c + 1] == 3 || grid[r][c + 1] == 5) &&
                hasValidPathImpl(r, c + 1, grid, visited)) return true;
        }

        visited[r][c] = false;
        return false;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> grid = {{2,4,3}, {6,5,2}};
    // vector<vector<int>> grid = {{1,2,1}, {1,2,1}};
    // vector<vector<int>> grid = {{1,1,2}};
    // vector<vector<int>> grid = {{1,1,1,1,1,1,3}};
    vector<vector<int>> grid = {{2},{2},{2},{2},{2},{2},{6}};
    // vector<vector<int>> grid = {{4,1}, {6,1}};
    cout << sol.hasValidPath(grid) << endl;
}
