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
    bool containsCycle(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> group(m * n, 0);
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int thisIdx = r * n + c;
                group[thisIdx] = thisIdx;

                int topIdx = (r - 1) * n + c;
                int leftIdx = r * n + (c - 1);
                char thisChar = grid[r][c];
                char topChar = r - 1 >= 0 ? grid[r - 1][c] : '.';
                char leftChar = c - 1 >= 0 ? grid[r][c - 1] : '*';

                int thisGroup = find(thisIdx, group);
                int topGroup = r - 1 >= 0 ? find(topIdx, group) : -1;
                int leftGroup = c - 1 >= 0 ? find(leftIdx, group) : -2;

                if (topGroup == leftGroup && thisChar == topChar && thisChar == leftChar)
                {
                    // cout << "(" << r << ", " << c << ")" << endl;
                    return true;
                }

                if (thisChar == topChar)
                {
                    uni(topIdx, thisIdx, group);
                }
                if (thisChar == leftChar)
                {
                    uni(leftIdx, thisIdx, group);
                }
            }
        }
        return false;
    }

    int find(int x, vector<int>& group)
    {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
    void uni(int x, int y, vector<int>& group)
    {
        int a = find(x, group);
        int b = find(y, group);
        if (a != b) group[a] = b;
    }
};

int main()
{
    Solution sol;

    // vector<vector<char>> grid = {{'a', 'a', 'a', 'a'},
    //                              {'a', 'b', 'b', 'a'},
    //                              {'a', 'b', 'b', 'a'},
    //                              {'a', 'a', 'a', 'a'}};

    // vector<vector<char>> grid = {{'c', 'c', 'c', 'a'},
    //                              {'c', 'd', 'c', 'c'},
    //                              {'c', 'c', 'e', 'c'},
    //                              {'f', 'c', 'c', 'c'}};

    // vector<vector<char>> grid = {{'a', 'b', 'b'},
    //                              {'b', 'z', 'b'},
    //                              {'b', 'b', 'a'}};

    // vector<vector<char>> grid = {{'b'}, {'b'}};

    // vector<vector<char>> grid = {{'b', 'a', 'c'},
    //                              {'c', 'a', 'c'},
    //                              {'d', 'd', 'c'},
    //                              {'b', 'c', 'c'}};

    vector<vector<char>> grid = {{'d', 'b', 'b'},
                                 {'c', 'a', 'a'},
                                 {'b', 'a', 'c'},
                                 {'c', 'c', 'c'},
                                 {'d', 'd', 'a'}};


    cout << sol.containsCycle(grid) << endl;
}
