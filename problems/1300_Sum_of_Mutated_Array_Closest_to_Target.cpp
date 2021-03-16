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
// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
const int MOD = 1000000007;
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int presum = 0;
        int idx = 0;
        int value = arr[0], diff = INT_MAX;
        for (int i = 0; i <= arr.back(); ++i)
        {
            while (idx < n && i == arr[idx])
            {
                presum += arr[idx];
                idx++;
            }

            int sum = presum + (n - idx) * i;
            // cout << "i: " << i << endl;
            // cout << "sum: " << sum << endl;
            if (abs(sum - target) < diff)
            {
                value = i;
                diff = abs(sum - target);
            }
        }
        return value;
    }
};

int main()
{
    Solution sol;

    // vector<int> arr = {4,9,3};
    // int target = 10;
    
    // vector<int> arr = {2,3,5};
    // int target = 10;

    // vector<int> arr = {60864,25176,27249,21296,20204};
    // int target = 56803;

    vector<int> arr = {15,1,1,1,1,1,1,1,1,1,1,1};
    int target = 50;

    cout << sol.findBestValue(arr, target) << endl;

}
