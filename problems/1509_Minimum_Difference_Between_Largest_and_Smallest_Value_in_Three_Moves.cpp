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
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/submissions/
const int MOD = 1000000007;
class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        if (nums.size() <= 4) return 0;

        priority_queue<int> small_pq;
        priority_queue<int, vector<int>, greater<int>> big_pq;

        for (int x : nums)
        {
            small_pq.push(x);
            if (small_pq.size() > 4) small_pq.pop();

            big_pq.push(x);
            if (big_pq.size() > 4) big_pq.pop();
        }

        vector<int> small_vec, big_vec;

        while (!small_pq.empty())
        {
            small_vec.push_back(small_pq.top());
            small_pq.pop();
        }
        while (!big_pq.empty())
        {
            big_vec.push_back(big_pq.top());
            big_pq.pop();
        }

        int ans = big_vec.front() - small_vec.back();
        for (int i = 0; i < 4; i++)
        {
            ans = min(ans, big_vec[i] - small_vec[3 - i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {1,5,0,10,14};
    // vector<int> nums = {6,6,0,1,1,4,6};
    vector<int> nums = {1,5,6,14,15};
    cout << sol.minDifference(nums) << endl;
}
