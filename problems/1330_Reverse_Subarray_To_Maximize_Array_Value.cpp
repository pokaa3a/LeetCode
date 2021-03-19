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
// https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
// https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/493570/O(N)-but-more-understandable-solution
const int MOD = 1000000007;
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums)
    {
        int sum = 0;
        int maxpre, maxpro, maxmid;
        maxpre = maxpro = maxmid = INT_MIN;

        int max0, max1, max2, max3;
        max0 = max1 = max2 = max3 = INT_MIN;

        int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int a = nums[i], b = nums[i + 1];
            int diff = abs(a - b);
            sum += diff;

            maxpre = max(maxpre, -diff + abs(nums[0] - b));
            maxpro = max(maxpro, -diff + abs(nums.back() - a));

            if (i > 0)
            {
                maxmid = max({maxmid,
                    max0 - a - b - diff,
                    max1 + a - b - diff,
                    max2 - a + b - diff,
                    max3 + a + b - diff});
            }
            max0 = max({max0,  a + b - diff});
            max1 = max({max1, -a + b - diff});
            max2 = max({max2,  a - b - diff});
            max3 = max({max3, -a - b - diff});
        }

        return sum + max({maxpre, maxpro, maxmid});
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {2,3,1,5,4};
    vector<int> nums = {2,4,9,24,2,1,10};
    cout << sol.maxValueAfterReverse(nums) << endl;
}
