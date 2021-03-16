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
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
const int MOD = 1000000007;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        unordered_map<int, vector<int>> group;
        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size(); ++i)
        {
            int size = groupSizes[i];
            if (group.find(size) == group.end())
            {
                group[size] = vector<int>();
            }
            group[size].push_back(i);
            if (group[size].size() == size)
            {
                ans.push_back(group[size]);
                group[size].clear();
            }
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    // vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<int> groupSizes = {2,1,3,3,3,2};

    auto ans = sol.groupThePeople(groupSizes);
    for (auto x: ans)
    {
        for (auto y: x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}
