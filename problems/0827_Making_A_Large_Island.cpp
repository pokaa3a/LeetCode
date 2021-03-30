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
private:
    unordered_map<int, int> area;
    vector<int> label;
    vector<bool> visited;
    int n;
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        n = grid.size();
        label.resize(n * n, -1);
        visited.resize(n * n, false);
        int res = 0;

        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 1 && !visited[r * n + c])
                {
                    int l = r * n + c;
                    area[l] = countArea(r, c, l, grid, visited);
                    res = max(res, area[l]);
                }
            }
        }

        // DEBUG
        // for (int r = 0; r < n; ++r)
        // {
        //     for (int c = 0; c < n; ++c)
        //     {
        //         if (grid[r][c] == 0) continue;
        //         cout << "(" << r << ", " << c << "): ";
        //         cout << "label: " << label[r * n + c] << ", ";
        //         cout << "area: " << area[label[r * n + c]] << endl;
        //     }
        // }


        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (grid[r][c] == 0)
                {
                    int a = 1;
                    int rOffset[] = {-1, 1,  0, 0};
                    int cOffset[] = {0,  0, -1, 1};
                    unordered_set<int> labs;
                    for (int i = 0; i < 4; ++i)
                    {
                        int rr = r + rOffset[i], cc = c + cOffset[i];
                        if (rr >= 0 && rr < n && cc >= 0 && cc < n && grid[rr][cc] == 1)
                        {
                            labs.insert(label[rr * n + cc]);
                        }
                    }
                    for (auto l : labs)
                    {
                        a += area[l];
                    }

                    res = max(res, a);
                }
            }
        }
        return res;
    }
    int countArea(int r, int c, int l, vector<vector<int>>& grid, vector<bool>& visited)
    {
        if (visited[r * n + c]) return 0;
        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if (grid[r][c] == 0) return 0;

        visited[r * n + c] = true;
        label[r * n + c] = l;
        int a = 1;

        int rOffset[] = {-1, 1,  0, 0};
        int cOffset[] = {0,  0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            int rr = r + rOffset[i], cc = c + cOffset[i];
            if (rr >= 0 && rr < n && cc >= 0 && cc < n)
            {
                a += countArea(rr, cc, l, grid, visited);
            }
        }
        return a;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> grid = {{1,0}, {0,1}};
    vector<vector<int>> grid = {{1,1}, {1,1}};

    cout << sol.largestIsland(grid) << endl;
}
