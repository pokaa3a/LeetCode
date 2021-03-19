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
    int numSubmat(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> colAccum(m, vector<int>(n, 0));

        int ans = 0;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (mat[r][c] == 0) continue;

                colAccum[r][c] = 1 + (c - 1 >= 0 ? colAccum[r][c - 1] : 0);
                
                int minColAccu = colAccum[r][c];
                for (int rr = r; rr >= 0; --rr)
                {
                    if (mat[rr][c] == 0) break;
                    ans += min(colAccum[rr][c], minColAccu);
                    minColAccu = min(minColAccu, colAccum[rr][c]);
                }
            }
        }

        // for (int r = 0; r < m; ++r)
        // {
        //     for (int c = 0; c < n; ++c)
        //     {
        //         cout << addMat[r][c] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << endl << endl;

        // for (int r = 0; r < m; ++r)
        // {
        //     for (int c = 0; c < n; ++c)
        //     {
        //         cout << colAccum[r][c] << " ";
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> mat = {{1,0,1}, {1,1,0}, {1,1,0}};
    // vector<vector<int>> mat = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    // vector<vector<int>> mat = {{1,1,1,1,1,1}};
    // vector<vector<int>> mat = {{1,0,1},{0,1,0},{1,0,1}};
    // vector<vector<int>> mat = {{1,1,1,1,0}, {1,0,0,1,0}, {0,0,1,0,1}, {0,1,0,0,0}};
    vector<vector<int>> mat = {{1,1,1,1,0,1,0},
                               {1,1,1,0,0,0,1},
                               {0,1,1,1,1,0,0},
                               {1,1,0,1,1,0,1},
                               {1,0,0,0,0,0,1},
                               {1,1,0,1,1,1,1},
                               {1,1,0,0,1,1,1}};

    cout << sol.numSubmat(mat) << endl;
}
