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
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
const int MOD = 1000000007;
class Solution {
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fibonacci = {1, 1, 2, 3, 5, 8};
        while (fibonacci.back() <= k)
        {
            int n = fibonacci.size();
            fibonacci.push_back(fibonacci[n - 2] + fibonacci[n - 1]);
        }

        int ans = 0;
        while (k > 0)
        {
            auto it = upper_bound(fibonacci.begin(), fibonacci.end(), k);
            k -= *(--it);
            ans++;
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    // cout << sol.findMinFibonacciNumbers(7) << endl;
    // cout << sol.findMinFibonacciNumbers(19) << endl;
    // cout << sol.findMinFibonacciNumbers(25) << endl;
    cout << sol.findMinFibonacciNumbers(513314) << endl;
}
