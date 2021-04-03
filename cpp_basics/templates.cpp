#include <iostream>
#include <vector>
using namespace std;

template <class T1, class T2>
void PrintNumber(T1 num1, T2 num2) {}

template<>
void PrintNumber<double, int>(double num1, int num2)
{
    cout << "double " << num1 << endl;
    cout << "int " << num2 << endl;
}

template <class T, int SIZE>
class Array
{
    const size_t size = SIZE;
    vector<T> data;
public:
    Array()
    {
        data.resize(size);
    }
};

int main()
{
    Array<double, 10> arr;
}