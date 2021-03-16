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
// https://leetcode.com/problems/closest-divisors/
const int MOD = 1000000007;
class Solution {
public:
    vector<int> closestDivisors(int num)
    {
        vector<int> cand1 = findClosestDivisors(num + 1);
        if (cand1[0] == cand1[1]) return cand1;
        vector<int> cand2 = findClosestDivisors(num + 2);

        return abs(cand1[0] - cand1[1]) < abs(cand2[0] - cand2[1]) ? cand1 : cand2;
    }
    vector<int> findClosestDivisors(int k)
    {
        vector<int> ans(2);
        for (int i = 1; i * i <= k; ++i)
        {
            if (k % i == 0)
            {
                ans[0] = i;
                ans[1] = k / i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    int num = 999;
    vector<int> ans = sol.closestDivisors(num);
    cout << ans[0] << ", " << ans[1] << endl;
}
