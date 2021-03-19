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
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        int cand1 = left.size() > 0 ? *max_element(left.begin(), left.end()) : 0;
        int cand2 = right.size() > 0 ? n - *min_element(right.begin(), right.end()) : 0;
        return max(cand1, cand2);
    }
};

int main()
{
    Solution sol;
    // vector<int> left = {4, 3};
    // vector<int> right = {0, 1};
    // int n = 4;

    vector<int> left = {};
    vector<int> right = {0,1,2,3,4,5,6,7};
    int n = 7;
    
    cout << sol.getLastMoment(n, left, right) << endl;
}
