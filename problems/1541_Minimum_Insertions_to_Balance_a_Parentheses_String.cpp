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
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/1055510/C%2B%2B-one-pass-count-'('-simple-solution-with-explanation
class Solution {
public:
    int minInsertions(string s)
    {
        int left = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];

            if (c == '(')
            {
                left++;
            }
            else
            {
                if (i + 1 < s.size() && s[i + 1] == ')')
                {
                    i++;
                }
                else
                {
                    ans++;
                }

                if (--left < 0)
                {
                    ans++;
                    left = 0;
                }
            }
        }
        return ans + left * 2;
    }
};

int main()
{
    Solution sol;

    // string s = "(()))";         // 1
    // string s = "())";              // 0
    // string s = "))())(";            // 3
    // string s = "((((((";            // 12
    // string s = ")))))))";           // 5
    string s = "()()()())))";       // 4

    cout << sol.minInsertions(s) << endl;
}
