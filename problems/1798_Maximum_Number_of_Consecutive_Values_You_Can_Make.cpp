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
// If we can make first x values, and we have another coin y s.t. y <= x + 1
// then we can also make first x + y values
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins)
    {
        sort(coins.begin(), coins.end());

        int sum = 0;
        for (int c : coins)
        {
            if (c <= sum + 1) sum += c;
            else break;
        }
        return sum + 1;
    }
};

int main()
{
    Solution sol;

    // vector<int> coins = {1, 3};
    // vector<int> coins = {1,1,1,4};
    vector<int> coins = {1,4,10,3,1};

    cout << sol.getMaximumConsecutive(coins) << endl;
}
