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
    int numOfSubarrays(vector<int>& arr)
    {
        int n = arr.size();
        
        vector<bool> sumIsOdd(n, false);
        // sumIsOdd[i] == True --> sum[0, ..., i] is odd
        vector<int> numOdds(n, 0);
        // numOdds[i] --> number of odd sums before arr[i] (inclusive)

        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                sumIsOdd[0] = arr[i] & 1;
                numOdds[0] = arr[i] & 1 ? 1 : 0;
            }
            else
            {
                sumIsOdd[i] = sumIsOdd[i - 1] ^ (arr[i] & 1);
                numOdds[i] = numOdds[i - 1] + sumIsOdd[i];
            }
        }

        // cout << "sumIsOdd:" << endl;
        // for (auto x : sumIsOdd) cout << x << " ";
        // cout << endl;

        // cout << "numOdds: " << endl;
        // for (auto x : numOdds) cout << x << " ";
        // cout << endl;

        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                ans = (ans + numOdds[n - 1]) % MOD;
            }
            else
            {
                if (sumIsOdd[i - 1])
                {
                    ans = (ans + (n - numOdds[n - 1]) - (i - numOdds[i - 1])) % MOD;
                }
                else
                {
                    ans = (ans + numOdds[n - 1] - numOdds[i - 1]) % MOD;
                }
            }
        }
        return (int)ans;
    }
};

int main()
{
    Solution sol;
    // vector<int> arr = {1,3,5};
    // vector<int> arr = {2,4,6};
    // vector<int> arr = {1,2,3,4,5,6,7};
    // vector<int> arr = {100, 100, 99, 99};
    vector<int> arr = {7};
    cout << sol.numOfSubarrays(arr) << endl;
}
