#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0, cur = 0, num = 0;
        char opt = '+';
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (opt == '+') {
                    cur += num;
                } else if (opt == '-') {
                    cur -= num;
                } else if (opt == '*') {
                    cur *= num;
                } else if (opt == '/') {
                    cur /= num;
                }
                num = 0;
                
                if (c == '+' || c == '-') {
                    ans += cur;
                    cur = 0;
                }
                opt = c;
            }
        }
        if (opt == '+') cur += num;
        else if (opt == '-') cur -= num;
        else if (opt == '*') cur *= num;
        else if (opt == '/') cur /= num;
        ans += cur;
        
        return ans;
    }
};