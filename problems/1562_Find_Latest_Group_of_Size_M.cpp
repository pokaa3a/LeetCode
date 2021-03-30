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
    int findLatestStep(vector<int>& arr, int m)
    {
        // left[i] = j means: j to i are consecutive ones
        // right[i] = j means: i to j are consecutive ones
        unordered_map<int, int> left, right;
        
        unordered_map<int, int> count;

        int lastStep = -1;
        for (int i = 0; i < arr.size(); ++i)
        {
            int bit = arr[i];

            int leftLen = 0, rightLen = 0;
            if (left.find(bit - 1) != left.end())
            {
                leftLen = bit - left[bit - 1];
                right.erase(left[bit - 1]);
                left.erase(bit - 1);
                
            }
            if (right.find(bit + 1) != right.end())
            {
                rightLen = right[bit + 1] - bit;
                left.erase(right[bit + 1]);
                right.erase(bit + 1);
            }

            int len = 1;
            if (leftLen == 0 && rightLen == 0)
            {
                len = 1;
                left[bit] = bit;
                right[bit] = bit;
            }
            else if (leftLen > 0 && rightLen == 0)
            {
                len = 1 + leftLen;
                left[bit] = bit - leftLen;
                right[bit - leftLen] = bit;
            }
            else if (leftLen == 0 && rightLen > 0)
            {
                len = 1 + rightLen;
                right[bit] = bit + rightLen;
                left[bit + rightLen] = bit;
            }
            else
            {
                len = 1 + leftLen + rightLen;
                left[bit - leftLen] = bit + rightLen;
                right[bit + leftLen] = bit - leftLen;
            }
            cout << "step: " << i + 1 << " len: " << len << endl;


            if (len == m) lastStep = i + 1;
        }
        return lastStep;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {3,5,1,2,4};
    int m = 1;

    cout << sol.findLatestStep(arr, m) << endl;
}
