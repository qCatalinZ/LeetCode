#include <iostream>
using namespace std;

int val(const char &a)
{
    switch(a)
    {
        case 'I':
            return 1;
         //   break;
        case 'V':
            return 5;
         //   break;
        case 'X':
            return 10;
         //   break;
        case 'L':
            return 50;
         //   break;
        case 'C':
            return 100;
         //   break;
        case 'D':
            return 500;
         //   break;
        case 'M':
            return 1000;
         //   break;
    }
    return 0;
}

class Solution
{
    public:
    int romanToInt(const string &s)
    {
        int year = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (i > 0 && val(s[i]) <= val(s[i-1]))
            {
                year += val(s[i]);
            }
            else if (i > 0 && val(s[i]) > val(s[i-1]))
            {
                year += val(s[i]);
                year -= val(s[i-1]);
                i--;
            }
            else if (i == 0)
            {
                year += val(s[i]);
            }
        }
        return year;
    }
};

int main(){}
