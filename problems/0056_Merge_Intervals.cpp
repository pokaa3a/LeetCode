#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> cur = intervals[0];
        for (auto next : intervals)
        {
            if (next[0] <= cur[1])
            {
                cur[1] = max(cur[1], next[1]);
            }
            else
            {
                ans.push_back(cur);
                cur = next;
            }
        }
        ans.push_back(cur);

        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans = sol.merge(intervals);
    for (auto x : ans)
    {
        cout << x[0] << "-" << x[1] << " ";
    }
}