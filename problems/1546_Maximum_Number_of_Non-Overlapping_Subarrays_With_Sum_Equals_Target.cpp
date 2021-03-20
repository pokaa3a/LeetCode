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
    int maxNonOverlapping(vector<int>& nums, int target)
    {
        int ans = 0;
        unordered_set<int> sums;
        sums.insert(0);

        int presum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            presum += num;
            if (sums.count(presum - target))
            {
                ans++;
                presum = 0;
                sums.clear();
                sums.insert(0);
            }
            else
            {
                sums.insert(presum);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {1,1,1,1,1};
    // int target = 2;

    // vector<int> nums = {-1,3,5,1,4,2,-9};
    // int target =  6;

    // vector<int> nums = {-2,6,6,3,5,4,1,2,8};
    // int target = 10;

    vector<int> nums = {0,0,0};
    int target = 0;

    cout << sol.maxNonOverlapping(nums, target) << endl;
}
