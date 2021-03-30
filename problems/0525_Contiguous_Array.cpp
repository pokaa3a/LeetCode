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
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        mp[0] = 0;

        int ans = 0;
        int diff = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                diff--;
            }
            else
            {
                diff++;
            }

            if (mp.find(diff) != mp.end())
            {
                ans = max(ans, i + 1 - mp[diff]);
            }
            else
            {
                mp[diff] = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {0, 1};
    vector<int> nums = {0,1,0};

    cout << sol.findMaxLength(nums) << endl;
}
