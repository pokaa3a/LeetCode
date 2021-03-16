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
// https://leetcode.com/problems/circle-and-rectangle-overlapping/
const int MOD = 1000000007;
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        // Is the circle cetner inside the rectangle?
        if (circleInTheRectangle(radius, x_center, y_center, x1, y1, x2, y2)) return true;

        // Are there intersections of rectangle edges and the circle?
        return edgeIntersectCircle(radius, x_center, y_center, x1, y1, x1, y2) ||
               edgeIntersectCircle(radius, x_center, y_center, x1, y1, x2, y1) ||
               edgeIntersectCircle(radius, x_center, y_center, x2, y2, x2, y1) ||
               edgeIntersectCircle(radius, x_center, y_center, x2, y2, x1, y2);
    }

    bool circleInTheRectangle(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        return x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2;
    }

    bool edgeIntersectCircle(int radius, int x_c, int y_c, int x1, int y1, int x2, int y2)
    {
        int x_closest = 0, y_closest = 0;
        // cout << radius << " " << x_c << " " << y_c << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        if (x1 == x2)
        {
            x_closest = x1;
            if (y_c >= max(y1, y2)) y_closest = max(y1, y2);
            else if (y_c <= min(y1, y2)) y_closest = min(y1, y2);
            else y_closest = y_c;
        }
        else if (y1 == y2)
        {
            y_closest = y1;
            if (x_c >= max(x1, x2)) x_closest = max(x1, x2);
            else if (x_c <= min(x1, x2)) x_closest = min(x1, x2);
            else x_closest = x_c;
        }
        else
        {
            return false;
        }

        // cout << "(" << x_closest << ", " << y_closest << ")" << endl;
        return ((x_c - x_closest) * (x_c - x_closest) + (y_c - y_closest) * (y_c - y_closest)) <= radius * radius;
    }
};

int main()
{
    Solution sol;
    // int radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    // int radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1;
    // int radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3;
    // int radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1;
    int radius = 2, x_center = 8, y_center = 6, x1 = 5, y1 = 1, x2 = 10, y2 = 4;

    cout << "Overlap: " << sol.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2) << endl;
}