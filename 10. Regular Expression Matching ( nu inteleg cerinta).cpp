#include <iostream>
#include <string>

using namespace std;

bool verifyPattern(const string &s, const string &aux)
{
    int index_s=0;

    for(int i=index_s; i < (int) s.length() ; ++i ) /// s
    {
        bool condition=true;

        if( (i + (int) aux.length()-1) < (int) s.length() )
        {
            return false;
        }

        for(int j=0; j < (int) aux.length() ; ++j )
        {
            if( /* i+j < (int)s.length() && */ aux[j] != s[i+j] )
            {
                condition=false;
                break;
            }
        }
        if(condition)
            return true;
        index_s++;
    }
    return false;
}

class Solution
{
public:

    bool isMatch(const string &s, const string &p)
    {
        if(s==p)
            return true;

      //  for(int i=0; i < (int) p.length() ; ++i)
        //{
          //  if( p[i] == '*' )
            //    return true;
        //}

        if( p[ (int) p.length() - 1 ] == '*' )
            return true;
        //if( p[ (int) p.length() - 1 ] == '.' )
        //{
            string aux;
            for(int i=0; i < (int)p.length()-2 ;++i )
            {
                aux=aux+p[i];
            }

            //int index_s=0;

            // de verificat daca stringul aux se gaseste in stringul s
        //}

        if(verifyPattern(s,aux))
            return true;
        return false;
    }
};

int main()
{


    return 0;
}
