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
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
const int MOD = 1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<long long> sums;
        for (int i = 0; i < nums.size(); i++)
        {
            long long sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sums.push_back(sum + nums[j]);
                sum += nums[j];
            }
        }
        sort(sums.begin(), sums.end());

        int ans = 0;
        for (int i = left - 1; i <= right - 1; i++)
        {
            ans = (ans + sums[i]) % MOD;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1,2,3,4};
    int left = 1, right = 5;

    cout << sol.rangeSum(nums, nums.size(), left, right) << endl;
}
