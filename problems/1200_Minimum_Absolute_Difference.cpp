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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<vector<int> > minimumAbsDifference(vector<int>& arr) {
    	sort(arr.begin(), arr.end());
    	int min_diff = INT_MAX;
    	for (int i = 1; i < arr.size(); ++i) {
    		min_diff = min(min_diff, arr[i] - arr[i - 1]);
    	}
    	vector<vector<int> > ans;
    	for (int i = 1; i < arr.size(); ++i) {
    		if (arr[i] - arr[i - 1] == min_diff) {
    			int a[] = {arr[i - 1], arr[i]};
    			ans.push_back(vector<int>(a, a + 2));
    		}
    	}
    	return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

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