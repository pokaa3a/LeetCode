#include <iostream>

using namespace std;

class Counter
{
private:
    unsigned int m_counter;
public:
    Counter() : m_counter(0) {}

    unsigned int get() { return m_counter; }

    void operator++() { m_counter++; }

    void operator--() { m_counter--; }
};

template<class T>
class SharedPointer
{
private:
    T* m_ptr;
    Counter* m_counter;
public:
    SharedPointer(T* ptr = nullptr)
    {
        m_ptr = ptr;
        m_counter = new Counter();
        if (ptr)
        {
            ++(*m_counter);
        }
    }

    SharedPointer(SharedPointer<T>& sp)
    {
        m_ptr = sp.m_ptr;
        m_counter = sp.m_ptr;
        ++(*m_counter);
    }

    ~SharedPointer()
    {
        --(*m_counter);
        if (m_counter->get() == 0)
        {
            delete m_ptr;
            delete m_counter;
        }
    }

    unsigned int use_count() { return m_counter->get(); }

    T* get() { return m_ptr; }

    T& operator*() { return *m_ptr; }

    T* operator->() { return m_ptr; }
};