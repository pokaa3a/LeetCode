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
    vector<int> findBuildings(vector<int>& heights)
    {
        vector<int> res;

        int highest = 0;
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            if (heights[i] > highest) res.push_back(i);
            highest = max(highest, heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
}
