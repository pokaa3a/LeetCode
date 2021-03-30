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
    int maxCoins(vector<int>& piles)
    {
        sort(piles.begin(), piles.end(), greater<int>());

        int rounds = piles.size() / 3;
        int ans = 0;
        for (int i = 1, j = 0; j < rounds; i += 2, j++)
        {
            // cout << "add " << piles[i] << endl;
            ans += piles[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> piles = {2,4,1,2,7,8};
    // vector<int> piles = {2,4,5};
    vector<int> piles = {9,8,7,6,5,4,3,2,1};

    cout << sol.maxCoins(piles) << endl;
}
