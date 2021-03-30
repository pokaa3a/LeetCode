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
// O(N*logk)
// N: number of all nodes
// k: number of linked lists
const int MOD = 1000000007;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) return nullptr;
        
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        for (auto root : lists)
        {
            if (!root) continue;
            pq.push(root);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (!pq.empty())
        {
            cur->next = pq.top();
            cur = cur->next;
            
            if (pq.top()->next)
            {
                pq.push(pq.top()->next);
            }
            pq.pop();
        }
        
        ListNode* output = dummy->next;
        delete(dummy);
        return output;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}