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
// https://leetcode.com/problems/construct-k-palindrome-strings/
const int MOD = 1000000007;
class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> count(26, 0);

        for (char c : s)
        {
            count[c - 'a']++;
        }

        int pairs = 0, odds = 0;
        for (int x : count)
        {
            if (x & 1)
            {
                odds++;
            }
            pairs += x / 2;
        }
        if (odds > k) return false;
        if (2 * pairs < k - odds) return false;

        return true;
    }
};

int main()
{
    Solution sol;
    string s;
    int k;

    s = "qlkzenwmmnpkopu";
    k = 15;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;

    s = "annabelle";
    k = 2;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;

    s = "leetcode";
    k = 3;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;

    s = "true";
    k = 4;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;

    s = "yzyzyzyzyzyzyzy";
    k = 2;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;

    s = "cr";
    k = 7;
    cout << "(" << s << ", " << k << "): " << sol.canConstruct(s, k) << endl;
}
