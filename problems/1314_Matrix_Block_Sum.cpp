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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> presum(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                presum[r][c] = (r - 1 >= 0 ? presum[r - 1][c] : 0) + 
                               (c - 1 >= 0 ? presum[r][c - 1] : 0) - 
                               (r - 1 >= 0 && c - 1 >= 0 ? presum[r - 1][c - 1] : 0) + 
                               mat[r][c];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                ans[r][c] = getSum(r - K, c - K, r + K, c + K, presum);
            }
        }
        return ans;
    }
    int getSum(int r1, int c1, int r2, int c2, vector<vector<int>>& presum)
    {
        // (r1, c1) -> top-left corner (inclusive)
        // (r2, c2) -> bottom-right corner (inclusive)
        int m = presum.size();
        int n = presum[0].size();

        r1 = max(r1, 0);
        c1 = max(c1, 0);
        r2 = min(r2, m - 1);
        c2 = min(c2, n - 1);

        int sum = presum[r2][c2];

        if (r1 - 1 >= 0)
        {
            sum -= presum[r1 - 1][c2];
        }
        if (c1 - 1 >= 0)
        {
            sum -= presum[r2][c1 - 1];
        }
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
        {
            sum += presum[r1 - 1][c1 - 1];
        }
        return sum;
    }
};

int test(vector<int>& arr)
{
    int a = arr[0] + arr[1];
    return a;
}

int main()
{   
    Solution sol;

    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    int K = 2;

    vector<vector<int>> ans = sol.matrixBlockSum(mat, K);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
