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
    int numSplits(string s)
    {
        unordered_map<char, int> left, right;
        for (char c : s)
        {
            right[c]++;
        }

        int ans = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            left[s[i]]++;
            if (--right[s[i]] == 0) right.erase(s[i]);

            if (left.size() == right.size()) ans++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // string s = "aacaba";
    // string s = "abcd";
    // string s = "aaaaa";
    string s = "acbadbaada";
    cout << sol.numSplits(s) << endl;
}
