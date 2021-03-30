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
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x1 = 0, x2 = 0;
            if (i >= 0) x1 = num1[i] - '0';
            if (j >= 0) x2 = num2[j] - '0';

            int res = x1 + x2 + carry;
            carry = res / 10;
            ans = to_string(res % 10) + ans;

            i--;
            j--;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    string num1 = "95";
    string num2 = "17";

    cout << sol.addStrings(num1, num2) << endl;
}
