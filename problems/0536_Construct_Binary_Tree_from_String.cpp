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
    TreeNode* str2tree(string s)
    {
        if (s.empty()) return nullptr;
        
        int i = 0;
        return myStr2Tree(i, s);
    }

    TreeNode* myStr2Tree(int& i, string& s)
    {
        int j = i;
        while (j < s.size() && (isdigit(s[j]) || s[j] == '-'))
        {
            j++;
        }

        int val = stoi(s.substr(i, j - i));
        i = j;

        TreeNode* node = new TreeNode(val);

        if (i < s.size() && s[i] == '(')
        {
            i++;
            node->left = myStr2Tree(i, s);
        }

        if (i < s.size() && s[i] == '(')
        {
            i++;
            node->right = myStr2Tree(i, s);
        }

        i++;
        return node;
    }
};

void printTree(TreeNode* node)
{
    if (!node) return;

    printTree(node->left);
    cout << node->val << endl;
    printTree(node->right);
}

int main()
{
    Solution sol;

    string s = "4(2(325)(1))(6(5))";
    // string s = "-4(2(3)(1))(6(5)(7))";

    TreeNode* root = sol.str2tree(s);
    printTree(root);
}
