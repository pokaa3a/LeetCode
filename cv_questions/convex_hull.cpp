// Return a list of points forming a convex polygon

#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
    Point() {}
    Point(int a, int b) : x(a), y(b) {}
};

class ConvexHull
{
public:
    // > 0 : p-q-r turns counter-clockwisely
    // < 0 : p-q-r turns clockwisely
    int orientation(const Point& p, const Point& q, const Point& r)
    {
        return (r.y - q.y) * (q.x - p.x) - (q.y - p.y) * (r.x - q.x);
    }

    vector<Point> convex_hull(vector<Point>& points)
    {
        int n = points.size();
        vector<Point> hull;
        if (n < 3) return hull;

        sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) -> bool 
        {
            return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
        });

        // build lower hull
        for (int i = 0; i < n; ++i)
        {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        // build upper hull
        for (int i = n - 2, t = hull.size() + 1; i >= 0; i--)
        {
            while (hull.size() >= t && orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        hull.pop_back();
        return hull;
    }

};

int main()
{
    vector<Point> points;
    points.push_back(Point(1, 1));
    points.push_back(Point(2, 2));
    points.push_back(Point(2, 0));
    points.push_back(Point(2, 4));
    points.push_back(Point(3, 2));
    points.push_back(Point(3, 3));
    points.push_back(Point(4, 2));

    ConvexHull ch;
    vector<Point> hull = ch.convex_hull(points);

    for (auto p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

}