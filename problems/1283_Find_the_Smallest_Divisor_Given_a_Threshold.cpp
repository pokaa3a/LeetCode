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
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
const int MOD = 1000000007;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        auto divide = [&](int d)
        {
            int sum = 0;
            for (auto x : nums)
            {
                sum += (x + d - 1)  / d;
            }
            return sum;
        };

        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        // find smallest d, s.t. divide(d) <= threshold
        while (lo < hi)
        {
            int mi = lo + (hi - lo) / 2;
            if (divide(mi) <= threshold) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {1,2,5,9};
    // vector<int> nums = {21212,10101,12121};
    vector<int> nums = {2,3,5,7,11};
    // int threshold = 6;
    // int threshold = 1000000;
    int threshold = 11;
    cout << sol.smallestDivisor(nums, threshold);
}
