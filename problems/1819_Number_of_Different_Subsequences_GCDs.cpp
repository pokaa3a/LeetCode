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
    int gcd(int a, int b)
    {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums)
    {
        int limit = *max_element(nums.begin(), nums.end());

        vector<bool> hash(limit + 1, false);
        for (int x : nums) hash[x] = true;

        int ans = 0;
        for (int i = 1; i <= limit; ++i)
        {
            int g = 0;
            for (int j = i; j <= limit; j += i)
            {
                if (hash[j])
                {
                    g = gcd(g, j);
                }
            }
            if (g == i) ans++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {6, 10, 3};
    cout << sol.countDifferentSubsequenceGCDs(nums) << endl;
}
