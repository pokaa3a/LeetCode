import os
import sys

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

/* Solution */
const int MOD = 1000000007;


int main()
{
    Solution sol;
}
'''
        )

# Parse problem title to regular file name
# e.g. 940. Distinct Subsequences II -> 0940_Distinct_Subsequences_II.cpp
def create_new_cpp(argv):
    argv[0] = '{0:04d}'.format(int(argv[0][:-1]))

    new_cpp = ''
    for x in argv:
        new_cpp += x + '_'
    
    new_cpp = new_cpp[:-1] + '.cpp'

    scripts_dir = os.path.dirname(os.path.realpath(__file__))
    problems_dir = os.path.join(scripts_dir, '..', 'problems')

    new_file = os.path.join(problems_dir, new_cpp)

    add_template(new_file)

    print "\nCreate new .cpp file: {filename}\n".format(filename=new_cpp)

# Usage:
# python new_code.py 1702. Maximum Binary String After Change
# -> create problems/1702_Maximum_Binary_String_After_Change.cpp
if __name__ == '__main__':
    problem_name = sys.argv

    create_new_cpp(problem_name[1:])
