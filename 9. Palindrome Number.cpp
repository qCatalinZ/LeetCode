#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x<0)
            return false;
        int array[1000],c=0;
        while(x)
        {
            array[c]=x%10;
            x=x/10;
            c++;
        }
        for(int i=0;i<c/2;++i)
        {
            if(array[i]!=array[c-i-1])
                return false;
        }
        return true;
    }
};

int main(){}
