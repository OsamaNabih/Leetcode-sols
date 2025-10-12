#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    map<string, int> vals = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900}
    };
    map<char, int> c_vals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.length())
        {
            if (i == s.length() - 1) {
                sum += c_vals[s[i++]];
                continue;
            }
            auto sub = s.substr(i, 2);
            if (vals[sub] != 0) 
            {
                sum += vals[sub];
                i += 2;
                continue;
            }
            sum += c_vals[s[i++]];
        }
        return sum;
    }
};