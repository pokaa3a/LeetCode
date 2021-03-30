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
    int getWinner(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> maxVal(n, 0);
        for (int i = 0; i < n; ++i)
        {
            maxVal[i] = i == 0 ? arr[i] : max(maxVal[i - 1], arr[i]);
        }

        for (int i = 0; i < n; ++i)
        {
            // cout << "i: " << i << endl;
            
            if (i == 0)
            {
                int j = min(n - 1, k);
                if (maxVal[j] == arr[0]) return arr[0];
            }
            else if (maxVal[i] == arr[i])
            {
                int j = min(n - 1, i + k - 1);
                if (maxVal[j] == arr[i]) return arr[i];
            }
        }
        return arr.back();
    }
};

int main()
{
    Solution sol;

    // vector<int> arr = {2,1,3,5,4,6,7};
    // int k = 2;

    // vector<int> arr = {3,2,1};
    // int k = 10;

    // vector<int> arr = {1,9,8,2,3,7,6,4,5};
    // int k = 7;

    vector<int> arr = {1,11,22,33,44,55,66,77,88,99};
    int k = 1000000000;

    cout << sol.getWinner(arr, k) << endl;
}
