#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(const int a, const int b)
{
    return (a>b)?b:a;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix="";
        int shortest=999999;
        for(int i=0;i < (int)strs.size();++i)
        {
            shortest=min(shortest,(int)strs[i].length());
        }

        int indexString=0;

        while(indexString<shortest)
        {
            for(int i=0; i<(int)strs.size()-1;++i)
            {
                if( strs[i][indexString] != strs[i+1][indexString] )
                {
                    return prefix;
                }
            }
            prefix=prefix+strs[0][indexString];
            indexString++;
        }

        return prefix;
    }
};

int main()
{
    return 0;
}
