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
// https://leetcode.com/problems/sort-the-matrix-diagonally/
const int MOD = 1000000007;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        // first row
        for (int c = 0; c < n; ++c)
        {
            int len = min(m, n - c);
            quickSort(0, c, 0 + len - 1, c + len - 1, mat);
        }

        // first col
        for (int r = 1; r < m; ++r)
        {
            int len = min(m - r, n);
            quickSort(r, 0, r + len - 1, 0 + len - 1, mat);
        }

        return mat;
    }
    vector<int> partition(int lo_r, int lo_c, int hi_r, int hi_c, vector<vector<int>>& mat)
    {
        int pivot = mat[hi_r][hi_c];
        int i_r = lo_r - 1, i_c = lo_c - 1;
        for (int offset = 0; lo_r + offset < hi_r && lo_c + offset < hi_c; ++offset)
        {
            int j_r = lo_r + offset, j_c = lo_c + offset;
            if (mat[j_r][j_c] <= pivot)
            {
                i_r++;
                i_c++;
                swap(mat[i_r][i_c], mat[j_r][j_c]);
            }
        }
        swap(mat[i_r + 1][i_c + 1], mat[hi_r][hi_c]);
        return vector<int>{i_r + 1, i_c + 1};
    }

    void quickSort(int lo_r, int lo_c, int hi_r, int hi_c, vector<vector<int>>& mat)
    {
        if (lo_r < hi_r && lo_c < hi_c)
        {
            vector<int> p = partition(lo_r, lo_c, hi_r, hi_c, mat);
            quickSort(lo_r, lo_c, p[0] - 1, p[1] - 1, mat);
            quickSort(p[0] + 1, p[1] + 1, hi_r, hi_c, mat);
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> mat = {{3,3,1,1}, {2,2,1,2}, {1,1,1,2}};

    vector<vector<int>> ans = sol.diagonalSort(mat);

    for (int r = 0; r < ans.size(); ++r)
    {
        for (int c = 0; c < ans[r].size(); ++c)
        {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}
