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
// https://leetcode.com/problems/remove-covered-intervals/
const int MOD = 1000000007;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        int ans = 1;
        int lo = intervals[0][0], hi = intervals[0][1];
        for (auto interval: intervals)
        {
            if (interval[1] <= hi) continue;
            else if (interval[0] == lo)
            {
                hi = max(hi, interval[1]);
                continue;
            }

            ans++;   
            lo = interval[0];
            hi = interval[1];
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<vector<int>> intervals = {{1,4}, {3,6}, {2,8}};
    // vector<vector<int>> intervals = {{1,4}, {2,3}};
    // vector<vector<int>> intervals = {{0,10}, {5,12}};
    // vector<vector<int>> intervals = {{3,10},{4,10},{5,11}};
    vector<vector<int>> intervals = {{1,2}, {1,4}, {3,4}};

    cout << sol.removeCoveredIntervals(intervals) << endl;
}
