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
    string encode(int num) {
        string s = "";
        int n = num + 1;
        while (n > 0) {
        	if (n % 2 == 0) {
        		s = "0" + s;
        	} else {
        		s = "1" + s;
        	}
        	n /= 2;
        }
        return s.substr(1);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	cout << sol.encode(107) << endl;
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