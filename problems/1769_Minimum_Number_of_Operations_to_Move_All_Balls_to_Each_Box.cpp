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
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> res(n, 0);

        int lftDist = 0, lftCount = 0;
        for (int i = 0; i < n; ++i)
        {
            res[i] += lftDist;
            if (boxes[i] == '1') lftCount++;
            lftDist += lftCount;
        }

        int rhtDist = 0, rhtCount = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            res[i] += rhtDist;
            if (boxes[i] == '1') rhtCount++;
            rhtDist += rhtCount;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    // string boxes = "110";
    string boxes = "001011";
    vector<int> res = sol.minOperations(boxes);
    for (int x : res) cout << x << " ";
}
