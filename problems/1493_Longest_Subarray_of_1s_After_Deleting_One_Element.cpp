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
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        // start of consecutive 1s and end of consecutive 1s 
        int one_start = -1, one_end = -1;

        int i = 0;
        int ans = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                i++;
                continue;
            }

            // nums[i] == 1
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == 1)
            {
                j++;
            }
            ans = max(ans, j - i + 1);

            if (one_end >= 0 && one_end + 2 == i)
            {
                ans = max(ans, j - one_start);
            }
            one_start = i;
            one_end = j;
            i = j + 1;
        }
        return min(ans, (int)nums.size() - 1);
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {1,1,0,1};
    // vector<int> nums = {0,1,1,1,0,1,1,0,1};
    // vector<int> nums = {1,1,1};
    // vector<int> nums = {1,1,0,0,1,1,1,0,1};
    // vector<int> nums = {0,0,0};
    vector<int> nums = {1,0,0,0,0};
    cout << sol.longestSubarray(nums) << endl;
}
