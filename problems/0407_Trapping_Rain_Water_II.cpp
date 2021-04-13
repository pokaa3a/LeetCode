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
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        // TODO
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap = {{12, 13,  1,  12},
                                     {13,  4, 13,  12},
                                     {13,  8, 10,  12},
                                     {12, 13, 12,  12},
                                     {13, 13, 13,  13}};
    // vector<vector<int>> heightMap = {{5,5,5,1},
    //                                  {5,1,1,5},
    //                                  {5,1,5,5},
    //                                  {5,2,5,8}};

    cout << sol.trapRainWater(heightMap) << endl;

}
