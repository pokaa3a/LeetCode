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
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        int lo = 1, hi = position.back();
        
        while (lo < hi)
        {
            int mi = lo + (hi - lo + 1) / 2;
            if (isValid(mi, position, m))
            {
                lo = mi;
            }
            else
            {
                hi = mi - 1;
            }
        }
        return lo;
    }
    bool isValid(int d, vector<int>& position, int m)
    {
        int prev = position.front();
        m--;
        for (int i = 1; i < position.size(); ++i)
        {
            if (abs(position[i] - prev) >= d)
            {
                m--;
                prev = position[i];
            }
        }
        return m <= 0;
    }
};

int main()
{
    Solution sol;

    // vector<int> position = {1,2,3,4,7};
    // int m = 3;

    vector<int> position = {5,4,3,2,1,1000000000};
    int m = 2;

    cout << sol.maxDistance(position, m) << endl;
}
