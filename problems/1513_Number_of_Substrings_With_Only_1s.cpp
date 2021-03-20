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
    int numSub1(string s)
    {
        long long ans = 0;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '0')
            {
                i++;
                continue;
            }

            int j = i;
            while (j + 1 < s.size() && s[j + 1] == '1')
            {
                j++;
            }

            long long len = j - i + 1;
            ans = (ans + ((len + 1) * len) / 2) % MOD;
        
            i = j + 1;
        }
        return ans;
    }

    int numSub(string s)
    {
        long long ans = 0;
        long long seq = 0;
        for (char c : s)
        {
            seq = c == '0' ? 0 : seq + 1;
            ans = (ans + seq) % MOD;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // string s = "0110111";
    // string s = "101";
    // string s = "111111";
    string s = "000";
    cout << sol.numSub(s) << endl;
}
