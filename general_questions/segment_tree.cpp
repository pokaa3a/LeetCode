// https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(vector<int>& arr)
    {
        n = arr.size();
        tree.resize(n);

        for (int i = 0; i < n; ++i) tree[n + i] = arr[i];
        for (int i = n - 1; i > 0; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int idx, int val)
    {
        tree[idx + n] = val;

        for (int i = idx + n; i < 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    int query(int lft, int rht)
    {
        int res = 0;

        for (lft += n, rht += n; lft < rht; lft >>= 1, rht >>= 1)
        {
            if (lft & 1) res += tree[lft++];
            if (rht & 1) res += tree[--rht];
        }
    }
};