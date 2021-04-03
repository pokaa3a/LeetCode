#include <iostream>

using namespace std;

struct Point2d
{
    double x;
    double y;
    double val;

    Point2d(double x_, double y_, double v_) : x(x_), y(y_), val(v_) {}
    Point2d(const Point2d& pt) : x(pt.x), y(pt.y), val(pt.val) {}
};

class Interpolation2d
{
private:
    Point2d _nw, _ne, _sw, _se;
public:
    Interpolation2d(Point2d nw, Point2d ne, Point2d sw, Point se) :
        _nw(nw), _ne(ne), _sw(sw), _se(ne) {}
    
    double interpolate(double x, double y)
    {
        double a = abs(_ne.x - __nw.x) * abs(_se.y - ne.y);

        double a_ne = abs(x - _ne.x) * abs(y - _ne.y) / a;
        double a_se = abs(x - _se.x) * abs(y - _se.y) / a;
        double a_nw = abs(x - _nw.x) * abs(y - _nw.y) / a;
        double a_sw = abs(x - _sw.x) * abs(y - _sw.y) / a;

        return _nw.val * a_se + _ne.val * a_sw + _sw.val * a_ne + _se.val * a_nw;
    }
};

int main()
{

}

