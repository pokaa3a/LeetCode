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
    bool canConvertString(string s, string t, int k)
    {
        if (s.size() != t.size()) return false;

        int shifts[26] = {};

        for (int i = 0; i < s.size(); ++i)
        {
            int diff = t[i] - s[i];
            diff = diff < 0 ? diff + 26 : diff;

            if (diff == 0) continue;

            if (shifts[diff] * 26 + diff > k) return false;
            shifts[diff]++;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    // string s = "input", t = "output";
    // int k = 9;

    // string s = "abc", t = "bcd";
    // int k = 10;

    // string s = "aab", t = "bbb";
    // int k = 27;

    string s = "atmtxzjkz", t = "tvbtjhvjd";
    int k = 35;

    cout << sol.canConvertString(s, t, k) << endl;
}
