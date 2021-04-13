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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        if (startFuel >= target) return 0;
        
        priority_queue<int> pq;
        int fuel = startFuel;
        int ans = 0;

        int i = 0;
        while (true)
        {
            if (i < stations.size() && stations[i][0] <= fuel)
            {
                pq.push(stations[i++][1]);
                continue;
            }

            // out of gas
            if (pq.empty()) return -1;

            fuel += pq.top();
            ans++;
            pq.pop();
            if (fuel >= target) return ans;
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    // int target = 1;
    // int startFuel = 1;
    // vector<vector<int>> stations = {};

    // int target = 100;
    // int startFuel = 1;
    // vector<vector<int>> stations = {{10, 100}};

    // int target = 100;
    // int startFuel = 10;
    // vector<vector<int>> stations = {{10,60}, {20,30}, {30,30}, {60,40}};

    int target = 100;
    int startFuel = 25;
    vector<vector<int>> stations = {{25,25}, {50,25}, {75,25}};

    cout << sol.minRefuelStops(target, startFuel, stations) << endl;
}
