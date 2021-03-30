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
    int pathSum(vector<int>& nums)
    {
        vector<vector<int>> table(4, vector<int>(8, -1));   // depth, position

        for (auto n : nums)
        {
            vector<int> digit = parse(n);
            table[digit[0]][digit[1]] = digit[2];

            // cout << digit[0] << " " << digit[1] << " " << digit[2] << endl;
        }

        int sum = 0;
        for (auto n : nums)
        {
            auto digit = parse(n);
            int d = digit[0], p = digit[1], v = digit[2];

            // is leaf
            if (d == 3 || (table[d + 1][p << 1] == -1 && table[d + 1][p << 1 | 1] == -1))
            {
                sum += calcSum(d, p, table);
            }
        }
        return sum;
    }

    int calcSum(int d, int p, vector<vector<int>>& table)
    {
        if (d == 0) return table[0][0];
        return table[d][p] + calcSum(d - 1, p >> 1, table);
    }

    vector<int> parse(int num)
    {
        int depth = num / 100 - 1;
        int pos = (num % 100) / 10 - 1;
        int val = (num % 100) % 10;

        return vector<int>{depth, pos, val};
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {113, 215, 221};
    // vector<int> nums = {113, 221};
    // vector<int> nums = {111,217,221,315,415};

    cout << sol.pathSum(nums) << endl;
}
