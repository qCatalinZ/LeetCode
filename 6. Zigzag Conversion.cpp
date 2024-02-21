#include <string>
#include <iostream>
using namespace std;

void swp(string &s)
{
    string a=s;
  //  int n=a.length();
    for(int i=0; i < a.length() ; ++i)
    {
        s[i]=a[a.length()-i-1];
    }
}


class Solution {
public:
    string convert(const string &s, const int &numRows)
    {
        if(numRows==1)
            return s;
        if(numRows==2)
        {
            int contor=0;
            string a=s;
            for(int i=0;i<s.length();++i)
            {
                if(i%2==0)
                {
                    a[contor]=s[i];
                    contor++;
                }
            }
            for(int i=0;i<s.length();++i)
            {
                if(i%2==1)
                {
                    a[contor]=s[i];
                    contor++;
                }
            }
            return a;
        }

        string a=s;
        int contorA=0;

        string lineZig[100];        /// lungime maxima string: numRows
        int contorLine=0;           // int contorLine=numRows;
        int vecLine=0;  // nr elem vec

        string diagZig[100];        /// lunime maxima string: numRows-2
        int contorDiag=0;           // int contorDiag=numRows-2;
        int vecDiag=0;  // nr elem vec

        for(int i=0;i<s.length();++i)
        {
            if( contorLine < numRows && contorDiag == 0 )
            {
                lineZig[vecLine]+=s[i];
                contorLine++;
            }
            else if( contorLine == numRows && contorDiag < numRows-2 )
            {
                diagZig[vecDiag]+=s[i];
                contorDiag++;
            }

            if( contorLine == numRows && contorDiag == numRows - 2 )
            {
                contorLine=0;
                contorDiag=0;
                vecLine++;
                vecDiag++;
            }
        }

        for(int i=0;i<=vecDiag;++i)
        {
            swp(diagZig[i]);
        }

        if(diagZig[vecDiag].length() < numRows - 2)
        {
            swp(diagZig[vecDiag]);
            while(diagZig[vecDiag].length() < numRows - 2)
            {
                diagZig[vecDiag]+='?';
            }
            swp(diagZig[vecDiag]);
        }

        if(vecDiag>0)
        {
            if(diagZig[vecDiag-1].length() < numRows - 2)
            {
                swp(diagZig[vecDiag-1]);
                while(diagZig[vecDiag-1].length() < numRows - 2)
                {
                    diagZig[vecDiag-1]+='?';
                }
                swp(diagZig[vecDiag-1]);
            }
        }

        for(int i=0; i < lineZig[0].length() ; ++i )
        {
            if(i==0)                                        /// inceput
            {
                for(int j=0; j <= vecLine ;++ j)
                {
                    if(lineZig[j].length())
                    {
                        a[contorA]=lineZig[j][0];
                        contorA++;
                    }
                }
            }
            else if( i>0 && i < lineZig[0].length() - 1)    /// mijloc
            {
                for(int j=0; j<=vecLine ;++j)
                {
                    if(lineZig[j].length()-1 >= i && lineZig[j].length())
                    {
                        a[contorA]=lineZig[j][i];
                        contorA++;
                    }

                    if( j <= vecDiag && diagZig[j].length() && diagZig[j].length()-1 >= i-1 )
                    {
                        if(a[contorA]=diagZig[j][i-1]=='?')
                            continue;
                        a[contorA]=diagZig[j][i-1];
                        contorA++;
                    }

                }
            }
            else if( i == lineZig[0].length()-1 )           /// final
            {
                for(int j=0; j<=vecLine;++j)
                {
                    if( lineZig[j].length() && lineZig[j].length()-1 >= i)
                    {
                        a[contorA]=lineZig[j][i];
                        contorA++;
                    }
                }
            }
        }

        return a;
    }
};

int main(){}
