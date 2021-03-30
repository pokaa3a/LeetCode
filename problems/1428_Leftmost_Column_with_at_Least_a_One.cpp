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
class BinaryMatrix {
    public:
    int get(int row, int col);
    vector<int> dimensions();
};

const int MOD = 1000000007;
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> hw = binaryMatrix.dimensions();
        int rows = hw[0], cols = hw[1];

        int lastC = cols - 1;
        for (int r = 0; r < rows; ++r)
        {
            while (binaryMatrix.get(r, lastC) == 1)
            {
                if (lastC == 0) return 0;
                lastC--;
            }
        }

        if (lastC == cols - 1) return -1;
        return lastC + 1;
    }
};

int main()
{
    Solution sol;
}
