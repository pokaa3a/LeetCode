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
    int minOperations(vector<int>& nums)
    {
        int ans = 0, maxMulTwo = 0;
        for (auto n : nums)
        {
            int addOne = 0, mulTwo = 0;
            int k = n;
            while (k > 0)
            {
                if (k & 1)
                {
                    k--;
                    addOne++;
                }
                else
                {
                    k = k >> 1;
                    mulTwo++;
                }
            }

            ans += addOne;
            maxMulTwo = max(maxMulTwo, mulTwo);
        }

        return ans + maxMulTwo;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {1,5};
    // vector<int> nums = {2,2};
    // vector<int> nums = {4,2,5};
    vector<int> nums = {7,4,3,2,0,2};
    // vector<int> nums = {2,0,2};

    cout << sol.minOperations(nums) << endl;
}
