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
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/discuss/1023517/C%2B%2B-beat-100
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int ans = 0;

        list<int> count;
        for (auto& row : grid)
        {
            auto lastOne = find(row.rbegin(), row.rend(), 1) - row.rbegin();
            count.push_back(lastOne);
        }

        for (int i = 0; i < n; ++i)
        {
            int j = 0;
            for (auto it = count.begin(); it != count.end(); ++it, ++j)
            {
                if (*it >= (n - 1) - i)
                {
                    ans += j;
                    count.erase(it);
                    break;
                }
            }
            if (j == n - i) return -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {{0,0,1}, {1,1,0}, {1,0,0}};

    cout << sol.minSwaps(grid) << endl;
}
