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
    int findKthPositive(vector<int>& arr, int k)
    {
        
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i == 0)
            {
                if (arr[i] > k) return k;
                else k -= arr[i] - 1;
            }
            else
            {
                if (arr[i] - arr[i - 1] > k) return arr[i - 1] + k;
                else k -= arr[i] - arr[i - 1] - 1;
            }
        }
        return arr.back() + k;
    }
};

int main()
{
    Solution sol;

    // vector<int> arr = {2,3,4,7,11};
    vector<int> arr = {1,2,3,4};
    int k = 2;

    cout << sol.findKthPositive(arr, k) << endl;
}
