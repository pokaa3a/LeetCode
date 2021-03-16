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
// https://leetcode.com/problems/sequential-digits/
const int MOD = 1000000007;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int low_digit = numDigits(low);
        int high_digit = numDigits(high);

        vector<int> ans;
        for (int d = low_digit; d <= high_digit; d++)     // num of digits
        {
            for (int i = 1; i + d - 1 <= 9; ++i)          // first digit starts with
            {
                int num = makeNum(i, d);
                if (num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
    int makeNum(int startWith, int numDigits)
    {
        string ans = string(numDigits, startWith + '0');
        for (int i = 1; i < numDigits; ++i)
        {
            ans[i] = ans[i - 1] + 1;
        }
        return stoi(ans);
    }
    int numDigits(int k)
    {
        int digit = 0;
        while (k > 0)
        {
            k /= 10;
            digit++;
        }
        return digit;
    }
};

int main()
{
    Solution sol;
    
    int low = 1000, high = 13000;
    vector<int> ans = sol.sequentialDigits(low, high);

    for (auto x : ans)
    {
        cout << x << " ";
    }
}
