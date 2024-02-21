#include <iostream>
using namespace std;

bool repeatingChar(char substring[100],const char &contor, const char &s)
{
    for(int i=0;i<contor;++i)
    {
        if(substring[i]==s)
            return false;
    }
    return true;
}

class Solution {
public:
    int lengthOfLongestSubstring(const string &s)
    {
        if(s.length()<1)
            return 0;

        char contor=1,maxContor=1,substring[100];
        substring[0]=s[0];
        for(int j=0;j< s.length();++j)
        {
            maxContor=contor>maxContor?(contor):(maxContor);
            substring[0]=s[j];
            contor=1;

            for(int i=j+1; i< s.length();++i)
            {
                if( repeatingChar(substring,contor,s[i]) )
                {
                    substring[contor]=s[i];
                    contor++;
                }
                else
                {
                    maxContor=contor>maxContor?(contor):(maxContor);
                    contor=1;
                    break;
                }
            }
        }
        maxContor=contor>maxContor?(contor):(maxContor);
        return (int)maxContor;

    }
};

int main(){}
