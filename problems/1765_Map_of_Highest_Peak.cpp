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
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, INT_MAX));

        queue<int> q;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (isWater[r][c] == 1)
                {
                    q.push(r * n + c);
                    height[r][c] = 0;
                }
            }
        }

        int h = 1;
        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)
            {
                int cur = q.front();
                q.pop();
                int r = cur / n;
                int c = cur % n;

                int x[] = {1, 0, -1,  0};
                int y[] = {0, 1,  0, -1};
                for (int k = 0; k < 4; ++k)
                {
                    if (r + x[k] >= 0 && r + x[k] < m && c + y[k] >= 0 && c + y[k] < n)
                    {
                        if (height[r + x[k]][c + y[k]] == INT_MAX) q.push((r + x[k]) * n + c + y[k]);
                        height[r + x[k]][c + y[k]] = min(height[r + x[k]][c + y[k]], h);
                    }
                }
            }
            h++;
        }
        return height;
    }
};

int main()
{
    Solution sol;
    // vector<vector<int>> isWater = {{0,1}, {0,0}};
    vector<vector<int>> isWater = {{0,0,1}, {1,0,0}, {0,0,0}};

    vector<vector<int>> height = sol.highestPeak(isWater);

    for (auto row : height)
    {
        for (auto h : row)
        {
            cout << h << " ";
        }
        cout << endl;
    }
}
