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
    int maxResult(vector<int>& nums, int k)
    {
        int ans = INT_MIN;
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(0, nums[0]));

        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sum = dq.front().second + nums[i];

            while (dq.size() > 0 && dq.back().second < sum) dq.pop_back();
            dq.push_back(make_pair(i, sum));

            while (dq.size() > 0 && dq.front().first + k <= i) dq.pop_front();
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {1,-1,-2,4,-7,3};
    // int k = 2;

    // vector<int> nums = {10,-5,-2,4,0,3};
    // int k = 3;

    vector<int> nums = {1,-5,-20,4,-1,3,-6,-3};
    int k = 2;

    cout << sol.maxResult(nums, k) << endl;
}
