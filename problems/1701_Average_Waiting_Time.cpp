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
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        double wait_time = 0;
        double idle_time = 0;

        for (auto c : customers)
        {
            double arrival = c[0];
            double time = c[1];

            wait_time += max(arrival, idle_time) + time - arrival;
            idle_time = max(arrival, idle_time) + time;
        }

        return wait_time / customers.size();
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> customers = {{5,2}, {5,4}, {10,3}, {20,1}};

    cout << sol.averageWaitingTime(customers) << endl;
}
