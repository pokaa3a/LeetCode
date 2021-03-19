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
    int numSubseq1(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i = 0; i < nums.size() && nums[i] <= (target + 1) / 2; ++i)
        {
            int diff = target - nums[i];
            if (diff < nums[i]) continue;

            // look for largest number j s.t. nums[j] <= diff
            int j = upper_bound(nums.begin(), nums.end(), diff) - nums.begin() - 1;
            
            long long comb = pow2(j - i);

            // cout << "[" << i << "]: " << nums[i] << " [" << j << "]: " << nums[j] << endl;

            ans = (ans + comb) % MOD;
        }
        return (int)ans;
    }

    int numSubseq(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long ans = 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (nums[i] + nums[j] <= target)
            {
                ans = (ans + pow2(j - i) % MOD) % MOD;
                i++;
            }
            else
            {
                // cout << "[" << i << "]: " << nums[i] << " [" << j << "]: " << nums[j] << endl;
                j--;
            }
        }
        return (int)ans;
    }

    long long pow2(int digit)
    {
        long long val = 1;
        const int bitSize = 62;
        long long one = 1;
        while (digit > 0)
        {
            long long x;
            if (digit > bitSize)
            {
                x = (one << bitSize) % MOD;
                digit -= bitSize;
            }
            else
            {
                x = (one << digit) % MOD;
                digit = 0;
            }
            val = (val * x) % MOD;
        }
        return val % MOD;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {3,5,6,7};   // 4
    // int target = 9;

    // vector<int> nums = {3,3,6,8};   // 6
    // int target = 10;

    // vector<int> nums = {2,3,3,4,6,7};   // 61
    // int target = 12;

    // vector<int> nums = {5,2,4,1,7,6,8};     // 127
    // int target = 16;

    vector<int> nums = {27,21,14,2,15,1,19,8,12,24,21,8,12,10,11,30,15,18,28,14,26,9,2,24,23,11,7,12,9,17,30,9,28,2,14,22,19,19,27,6,15,12,29,2,30,11,20,30,21,20,2,22,6,14,13,19,21,10,18,30,2,20,28,22};
    int target = 31;

    cout << sol.numSubseq(nums, target) << endl;

}
