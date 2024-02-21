#include <iostream>
#include <string>
using namespace std;

string digitToString(const int digit, const int i) // i reprezinta gradul
{
    switch(i)
    {
        case 3:
            switch(digit)
            {
                case 1:
                    return "M";
                    break;
                case 2:
                    return "MM";
                    break;
                case 3:
                    return "MMM";
                    break;
            }
            break;
        case 2:
            switch(digit)
            {
                case 9:
                    return "CM";
                    break;
                case 8:
                    return "DCCC";
                    break;
                case 7:
                    return "DCC";
                    break;
                case 6:
                    return "DC";
                    break;
                case 5:
                    return "D";
                    break;
                case 4:
                    return "CD";
                    break;
                case 3:
                    return "CCC";
                    break;
                case 2:
                    return "CC";
                    break;
                case 1:
                    return "C";
                    break;
            }
            break;
        case 1:
            switch(digit)
            {
                case 9:
                    return "XC";
                    break;
                case 8:
                    return "LXXX";
                    break;
                case 7:
                    return "LXX";
                    break;
                case 6:
                    return "LX";
                    break;
                case 5:
                    return "L";
                    break;
                case 4:
                    return "XL";
                    break;
                case 3:
                    return "XXX";
                    break;
                case 2:
                    return "XX";
                    break;
                case 1:
                    return "X";
                    break;
            }
            break;
        case 0:
            switch(digit)
            {
                case 9:
                    return "IX";
                    break;
                case 8:
                    return "VIII";
                    break;
                case 7:
                    return "VII";
                    break;
                case 6:
                    return "VI";
                    break;
                case 5:
                    return "V";
                    break;
                case 4:
                    return "IV";
                    break;
                case 3:
                    return "III";
                    break;
                case 2:
                    return "II";
                    break;
                case 1:
                    return "I";
                    break;
            }
            break;
    }
    return "";
}

class Solution {
public:
    string intToRoman(int num)
    {
        string roman;
        int vector[5], contor=0;
        while(num)
        {
            vector[contor]=num%10;
            num/=10;
            contor++;
        }

        for(int i=contor-1; i>=0; --i)
        {
            roman=roman+digitToString(vector[i],i);
        }

        return roman;
    }
};

int main()
{

    return 0;
}
