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

// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/988056/Python-O(n)-Sliding-Window-with-detailed-explanation
class Solution {
public:
    int minMoves(vector<int>& nums, int k)
    {
        vector<int> one_idx;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                one_idx.push_back(i - one_idx.size());
            }
        }

        int med = k / 2;
        int cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur += abs(one_idx[i] - one_idx[med]);
        }

        // rolling window
        int ans = cur;
        for (int i = 1; i + k - 1 < one_idx.size(); ++i)
        {
            int new_med = i + k / 2;
            if ((k & 1) == 0)
            {
                cur += one_idx[new_med] - one_idx[med];
            }
            cur -= one_idx[med] - one_idx[i - 1];
            cur += one_idx[i + k - 1] - one_idx[new_med];
            ans = min(ans, cur);
            med = new_med;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1,0,0,1,0,1};
    int k = 2;

    cout << sol.minMoves(nums, k) << endl;
}
