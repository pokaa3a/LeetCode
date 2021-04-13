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
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) return -1;

        vector<int> croak(5, 0);
        int max_frogs = 0;
        for (char c : croakOfFrogs) {
        	if (c == 'c') {
        		croak[0]++;
        	} else if (c == 'r') {
        		if (croak[0] == 0) return -1;
        		croak[0]--;
        		croak[1]++;
        	} else if (c == 'o') {
        		if (croak[1] == 0) return -1;
        		croak[1]--;
        		croak[2]++;
        	} else if (c == 'a') {
        		if (croak[2] == 0) return -1;
        		croak[2]--;
        		croak[3]++;
        	} else if (c == 'k') {
        		if (croak[3] == 0) return -1;
        		croak[3]--;
        		croak[4]++;
        	} else {
        		return -1;
        	}
        	max_frogs = max(max_frogs, accumulate(croak.begin(), croak.end(), 0));
        	croak[4] = 0;
        }
        if (accumulate(croak.begin(), croak.end(), 0) != 0) return -1;
        return max_frogs;
    }
};

int main()
{
    Solution sol;

    // string croakOfFrogs = "croakcroak";
    string croakOfFrogs = "crcoakroak";
    cout << sol.minNumberOfFrogs(croakOfFrogs) << endl;
}
