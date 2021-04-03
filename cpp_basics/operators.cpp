#include <iostream>

using namespace std;

template <class T>
class Number
{
private:
    T _x;
public:
    Number(const T& x) : _x(x) {}

    bool operator< (const Number& rhs)
    {
        return this->_x < rhs._x;
    }

    bool operator== (const Number& rhs)
    {
        return this->_x == rhs._x;
    }

    void operator= (const Number& rhs)
    {
        this->_x = rhs._x;
    }

    // prefix increment
    Number & operator++()
    {
        _x += T(1);
        return *this;
    }

    Number operator++(int)
    {
        Number tmp(_x);
        ++_x;
        return tmp;
    }

    friend ostream& operator<<(ostream& os, const Number& n)
    {
        os << n._x;
        return os;
    }
};

template <class T, int SIZE>
class Array
{
private:
    T _data[SIZE];
public:
    Array(T (&x)[SIZE])
    {
        copy(begin(x), end(x), begin(_data));
    }
    T* data()
    {
        return _data;
    }
    Array operator+(const T& x)
    {
        T newData[SIZE];
        for (int i = 0; i < SIZE; ++i)
        {
            newData[i] = _data[i] + x;
        }
        return Array(newData);
    }
    Array operator*(const T& x)
    {
        T newData[SIZE];
        for (int i = 0; i < SIZE; ++i)
        {
            newData[i] = _data[i] * x;
        }
        return Array(newData);
    }
    T& operator[] (int idx)
    {
        return _data[idx];
    }
};

int main()
{
    double data[] = {1,2,3,4,5};
    Array<double, 5> a(data);

    Array<double, 5> b = a + 1.0;

    Array<double, 5> c = a * 2.0;

    for (int i = 0; i < 5; ++i)
    {
        cout << "(a, b, c) = (" << a[i] << ", " << b[i] << ", " << c[i] << ")" << endl; 
    }
}