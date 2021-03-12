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

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        unordered_map<int, int> count;
        queue<int> q;

        for (int student: students)
        {
            q.push(student);
            count[student]++;
        }

        int i = 0;
        while (!q.empty())
        {
            if (q.front() == sandwiches[i])
            {
                // consume sandwich
                count[q.front()]--;
                q.pop();
                i++;
            }
            else
            {
                // skip sandwich
                q.push(q.front());
                q.pop();
            }

            if (i < sandwiches.size() && count[sandwiches[i]] == 0)
            {
                int the_other_shape = sandwiches[i] ^ 1;
                return count[the_other_shape];
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;

    // vector<int> students{1, 1, 0, 0};
    // vector<int> sandwiches{0, 1, 0, 1};
    vector<int> students{1,1,1,0,0,1};
    vector<int> sandwiches{1,0,0,0,1,1};
    cout << sol.countStudents(students, sandwiches) << endl;
}
