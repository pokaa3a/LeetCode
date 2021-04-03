#include <iostream>

using namespace std;

int main()
{
    auto integrate = [](auto&& f, double x0, double x1, int n) -> double
    {
        double sum = 0;
        const int step = (x1 - x0) / n;

        for (double x = x0; x <= x1; x += step)
        {
            sum += f(x) * step;
        }
        return sum;
    }

    auto func = [](double x) -> double
    {
        const double k = 2.3;
        return k * x * x;
    }

    double integration = integrate(func, 0, 1, 512);
}