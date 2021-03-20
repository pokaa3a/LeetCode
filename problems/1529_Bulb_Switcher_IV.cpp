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
    int minFlips(string target)
    {
        int ans = 0;
        for (int i = target.size() - 1; i >= 0; --i)
        {
            if (i == 0) ans += target[0] == '1' ? 1 : 0;
            else
            {
                if (target[i] != target[i - 1]) ans++;
            }
        }    
        return ans;
    }
};

int main()
{
    Solution sol;

    // string target =  "10111";
    // string target = "101";
    // string target = "00000";
    string target = "001011101";

    cout << sol.minFlips(target) << endl;
}
