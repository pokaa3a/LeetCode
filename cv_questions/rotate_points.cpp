#include <iostream>
#include <cmath>

using namespace std;

class Point2d
{
public:
    Point2d(double _x, double _y) : x(_x), y(_y) {}

    double x;
    double y;

    friend ostream &operator<< (ostream& os, const Point2d& pt)
    {
        os << pt.x << "," << pt.y;
        return os;
    }
};

class Point3d
{
public:
    point3d(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    double x;
    double y;
    double z;

    friend ostream &operator<< (ostream& os, const Point3d& pt)
    {
        os << pt.x << "," << pt.y << "," << pt.z;
        return os;
    }
};

class Rotation2d
{
private:
    double theta;
public:
    Rotation2d(double _theta) : theta(_theta) {}

    Point2d operator* (const Point2d& pt)
    {
        // 2D rotation:
        // [ cos(theta), -sin(theta),
        //   sin(theta),  cos(theta)] 
        Point2d pt_rotated(
            cos(theta) * pt.x - sin(theta) * pt.y,
            sin(theta) * pt.x + cos(theta) * pt.y);
        return pt_rotated;
    }
};

class Rotation3d
{
private:
    double axis[3]; // unit length
    double theta;
public:
    Rotation3d(double* data)
    {
        theta = sqrt(data[0]*data[0] + data[1]*data[1] + data[2]*data[2]);
        axis[0] = data[0] / theta;
        axis[1] = data[1] / theta;
        axis[2] = data[2] / theta;
    }

    Point3d operator* (const Point3d& pt)
    {
        // Using quaternion
        // q = w + x*i + y*j + z*k
        double w = cos(theta/2);
        double x = axis[0] * sin(theta/2);
        double y = axis[1] * sin(theta/2);
        double z = axis[2] * sin(theta/2);

        double s = w*w + x*x + y*y + z*z;   // normally should be 1

        double out_x, out_y, out_z;
        out_x = 2 * ((-y*y - z*z) * pt[0] + (x*y - w*z) * pt[1] + (x*z + w*y) * pt[2]) / s + pt[0];
        out_y = 2 * ((x*y + w*z) * pt[0] + (-x*x - z*z) * pt[1] + (y*z - w*x) * pt[2]) / s + pt[1];
        out_z = 2 * ((x*z - w*y) * pt[0] + (y*z + w*x) * pt[1] + (-x*x - y*y) * pt[2]) / s + pt[2];

        return Point3d(out_x, out_y, out_z);
    }
};

int main()
{
    Point2d p2d(1.0, 2.5);
    Rotation2d rot2d(0.11);
    Rotation2d rot2d_inverse(-0.11);

    Point2d p2d_rotated = rot2d * p2d;
    cout << p2d_rotated << endl;
    cout << rot2d_inverse * p2d_rotated << endl;

    Point3d p3d(1.0, 2.0, 1.5);
    Rotation3d rot3d(0.12);

}