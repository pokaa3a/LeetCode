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
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int, int> mods;

        for (int x : arr)
        {
            int m = x % k;
            if (m < 0) m += k;

            int target = k - m;
            if (m == 0) target = 0;

            if (mods.find(target) != mods.end())
            {
                if (--mods[target] == 0) mods.erase(target);
            }
            else
            {
                if (mods.find(m) == mods.end())
                {
                    mods[m] = 0;
                }
                mods[m]++;
            }
            // cout << mods.size() << endl;
        }
        return mods.empty();
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {1,2,3,4,5,10,6,7,8,9};
    // int k = 5;

    // vector<int> nums = {1,2,3,4,5,6};
    // int k = 7;

    // int k = 10;

    // vector<int> nums = {-10, 10};
    // int k = 2;

    vector<int> nums = {-1,1,-2,2,-3,3,-4,4};
    int k = 3;

    // vector<int> nums = {-4,-7,5,2,9,1,10,4,-8,-3};
    // int k = 3;

    cout << sol.canArrange(nums, k) << endl;
}
