import glob
import os

# Write C++ template to the file
def add_template(filepath):
    with open(filepath, 'w') as f:
        f.write('''\
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



int main()
{
    Solution sol;
}
'''
        )


# Fomulate file name (the original file name is assumed to be the title of the problem,
# e.g. "940. Distinct Subsequences II")
# ../problems/940. Distinct Subsequences II -> ../problems/0940_Distinct_Subsequences_II.cpp
def formulate(filepath):
    filename = os.path.basename(filepath)

    if not ' ' in filename:
        return

    parts = filename.split()

    parts[0] = '{0:04d}'.format(int(parts[0][:-1]))
    if '.' in parts[-1]:
        parts[-1] = os.path.splitext(parts)[0]

    new_filename = ''
    for x in parts:
        new_filename += x + '_'

    new_filename = new_filename[:-1] + '.cpp'
    
    src_path = filepath
    dst_path = filepath.replace(filename, new_filename)

    print src_path + ' => ' + dst_path
    os.rename(src_path, dst_path)

    add_template(dst_path)

def main():
    scripts_dir = os.path.dirname(os.path.realpath(__file__))
    problems_dir = os.path.join(scripts_dir, '..', 'problems')

    cpp_files = glob.glob(os.path.join(problems_dir, '*'))
    for f in cpp_files:
        formulate(f)

if __name__ == '__main__':
    main()
