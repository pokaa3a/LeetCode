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
    int maximumBeauty(vector<int>& flowers)
    {
        unordered_map<int, int> position;
        int n = flowers.size();
        vector<int> maxsum(n, 0);   // maxsum[i] == max sum of first i + 1 elements

        for (int i = 0; i < n; ++i)
        {
            // update presums
            if (i == 0) maxsum[0] = max(0, flowers[0]);
            else maxsum[i] = max(0, maxsum[i - 1]) + max(0, flowers[i]);
            
            // record positions
            if (position.find(flowers[i]) == position.end()) position[flowers[i]] = i;
        }

        int ans = INT_MIN;
        for (int i = n - 1; i >= 1; i--)
        {
            int val = flowers[i];

            if (position.find(val) != position.end())
            {
                // cout << "val : " << val << endl;

                int head = position[val];
                if (head >= i) continue;

                // cout << "head : " << head << endl;

                int candidate = maxsum[i - 1] - maxsum[head] + 2 * val;
                // cout << "candidate = " << maxsum[i - 1] << " - " << maxsum[head] << endl;

                ans = max(ans, candidate);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> flowers = {1,2,3,1,2};
    // vector<int> flowers = {100,1,1,-3,1};
    vector<int> flowers = {-1,-2,0,-1};
    cout << sol.maximumBeauty(flowers) << endl;
}
