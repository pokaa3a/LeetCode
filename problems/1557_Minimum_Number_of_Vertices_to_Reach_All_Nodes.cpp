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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        vector<int> incomings(n, 0);

        for (auto edge : edges)
        {
            int to = edge[1];
            incomings[to]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (incomings[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> edges = {{0,1}, {0,2}, {2,5}, {3,4}, {4,2}};
    int n = 6;

    vector<int> nodes = sol.findSmallestSetOfVertices(n, edges);

    for (auto i : nodes)
    {
        cout << i << " ";
    }
}
