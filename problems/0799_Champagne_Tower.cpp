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
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> cups(101 * 100 / 2);

        int i = 0;
        for (int r = 0; r < 100; ++r)
        {
            int row_size = r + 1;
            int head = i;
            int prev_head = head - (row_size - 1);

            for (int c = 0; c < row_size; ++c)
            {
                if (i == 0) cups[i] = poured;
                else
                {
                    double left = c == 0 ? 0 : cups[prev_head + c - 1];
                    double right = c == row_size - 1 ? 0 : cups[prev_head + c];

                    cups[i] = (left > 1 ? (left - 1) / 2 : 0) + (right > 1 ? (right - 1) / 2 : 0);

                    // cout << "cups[" << i << "] = " << cups[i] << endl;
                }
                if (r == query_row && c == query_glass)
                {
                    return cups[i] >= 1 ? 1 : cups[i];
                }

                i++;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;

    // double poured = 25, query_row = 6, query_glass = 1;
    double poured = 1, query_row = 0, query_glass = 0;
    cout << sol.champagneTower(poured, query_row, query_glass) << endl;
}
