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
// https://leetcode.com/problems/path-with-maximum-probability/
const int MOD = 1000000007;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); ++i)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back(make_pair(b, p));
            graph[b].push_back(make_pair(a, p));
        }
        
        vector<double> prob(n, 0);

        // BFS
        queue<int> q;
        q.push(start);
        prob[start] = 1.0;

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                int cur = q.front();
                q.pop();

                for (auto next: graph[cur])
                {
                    int nextNode = next.first;
                    double nextProb = next.second;
                    if (prob[cur] * nextProb > prob[nextNode])
                    {
                        prob[nextNode] = prob[cur] * nextProb;
                        q.push(nextNode);
                    }
                }
            }
        }
        return prob[end];
    }
};

int main()
{
    Solution sol;

    // int n = 3;
    // vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    // vector<double> succProb = {0.5, 0.5, 0.2};
    // int start = 0;
    // int end = 2;

    int n = 3;
    vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    vector<double> succProb = {0.5, 0.5, 0.3};
    int start = 0;
    int end = 2;

    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;
}
