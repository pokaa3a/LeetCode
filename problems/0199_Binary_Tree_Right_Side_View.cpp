#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		helper(root, 1, ans);
		return ans;
	}

	void helper(TreeNode* root, int level, vector<int>& ans)j
	{
		if (!root) return;

		if (level > ans.size())
		{
			ans.push_back(root->val);
		}
		helper(root->right, level + 1, ans);
		helper(root->left, level + 1, ans);
	}
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);

	n1->left = n2;
	n1->right = n3;
	n2->left = n5;
	n5->left = n4;

	Solution sol;
	vector<int> sides = sol.rightSideView(n1);
	for (int i = 0; i < sides.size(); ++i) {
		cout << sides[i] << " ";
	}
}