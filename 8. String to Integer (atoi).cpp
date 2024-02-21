#include <iostream>
#include <string>
using namespace std;

int charToInt(const char &c)
{
    if(c=='0')
        return 0;
    if(c=='1')
        return 1;
    if(c=='2')
        return 2;
    if(c=='3')
        return 3;
    if(c=='4')
        return 4;
    if(c=='5')
        return 5;
    if(c=='6')
        return 6;
    if(c=='7')
        return 7;
    if(c=='8')
        return 8;
    if(c=='9')
        return 9;
    return 0;
}

bool verifyCharIsInt(const char &c)
{
    if(c=='0')
        return true;
    if(c=='1')
        return true;
    if(c=='2')
        return true;
    if(c=='3')
        return true;
    if(c=='4')
        return true;
    if(c=='5')
        return true;
    if(c=='6')
        return true;
    if(c=='7')
        return true;
    if(c=='8')
        return true;
    if(c=='9')
        return true;
    return false;
}




class Solution
{
public:
    int myAtoi(string s)
    {
        bool semn=false;
        int aux=0;
        int x[11]={10,10,10,10,10,10,10,10,10,10,69}; // daca x[10]!=69 inseamna ca nr depaseste limita
        int l=0;

        for(int i=0 ; i < (int)s.length() ; ++i)
        {
            if(s[i]==' ' || s[i]=='0' || (s[i]=='+' &&  (i+1)<(int)s.length() && verifyCharIsInt(s[i+1]) ))
            {
                if(s[i]=='0' && (i+1)<(int)s.length() && !verifyCharIsInt(s[i+1]))
                    return 0;
                continue;
            }
            else if(verifyCharIsInt(s[i]))
            {
                do
                {
                    x[l]=charToInt(s[i]);
                    l++;
                    i++;
                    if(l==11)
                    {
                        return 2147483647;
                    }
                }
                while(verifyCharIsInt(s[i]));

                if(l<10)
                {
                    for(int z=0; z<l; ++z)
                    {
                        aux=aux*10+x[z];
                    }
                    return aux;
                }
                else if(l==10)
                {
                    char maxInt_plus[10]={2,1,4,7,4,8,3,6,4,7};
                    bool check=true;
                    for(int h=0; h<10;++h)
                    {
                        if( x[h]<maxInt_plus[h] )
                            check=false;
                        if(x[h]>maxInt_plus[h] && check )
                            return 2147483647;
                        else
                        {
                            aux=aux*10+x[h];
                        }

                    }
                    return aux;
                }
            }
            else if(s[i]=='-' && (i+1)<(int)s.length() && verifyCharIsInt(s[i+1]))
            {
                semn=true;
                i++;

                while( verifyCharIsInt(s[i]) && charToInt(s[i]) == 0 )
                {
                    i++;
                }

                if( verifyCharIsInt(s[i])== false )
                    return 0;

                do
                {
                    x[l]=charToInt(s[i]);
                    l++;
                    i++;
                    if(l==11)
                    {
                        return -2147483648;
                    }
                }
                while(verifyCharIsInt(s[i]));

                if(l<10)
                {
                    for(int z=0; z<l; ++z)
                    {
                        aux=aux*10+x[z];
                    }
                    aux=-aux;
                    return aux;
                }
                else if(l==10)
                {
                    bool checkSemn=true;
                    char maxInt_minus[10]={2,1,4,7,4,8,3,6,4,8};
                    bool check=true;
                    for(int h=0; h<10;++h)
                    {
                        if( x[h]<maxInt_minus[h] )
                            check=false;
                        if(x[h]>maxInt_minus[h] && check )
                            return -2147483648;
                        else
                        {

                            if(checkSemn==false)
                            {
                                aux=aux*10-x[h];
                            }
                            else
                            {
                                aux=aux*10+x[h];
                            }
                        }

                        if(checkSemn)
                        {
                            aux=-aux;
                            checkSemn=false;
                        }

                    }
                    return aux;
                }
            }
            else return 0;
        }
        return 0;



    }
};


/*
class Solution
{
public:

    int myAtoi(const string &s)
    {
        int x=0;
        bool semn=false;
        bool foundNumber=false;
        bool exit=false;
        for(int i=0; i < s.length(); ++i)
        {
            if(s[i]==' ')
                continue;
            if(s[i]=='-' && (i+1)<s.length() && verifyCharIsInt(s[i+1]))
                semn=true;

            if(verifyCharIsInt(s[i]))
            {
                foundNumber=true;
            }
            else if(s[i]!=' ' && s[i]!='-' && s[i]!='+')
                return 0;
            while(foundNumber && verifyCharIsInt(s[i]) && exit==false)
            {
                if(lungime(x)==9)
                {
                    break;
                }

                x=x*10+charToInt( s[i] );
                i++;

            }

            if(verifyCharIsInt(s[i]))           // probabil trb sa bunem si: lungime(x)==9
            {
                if(semn)
                {
                    char maxInt_minus[10]={2,1,4,7,4,8,3,6,4,8};
                                       //  2,1,4,3,8,4,7,4,1,2
                    bool check=true;
                    for(int j=0; j<9;++j)
                    {
                        if( cifra[j]<maxInt_minus[j] )
                            check=false;
                        if(cifra[j]>maxInt_minus[j] && check )
                            return 0;
                        else x=x*10+cifra[j];
                    }
                    x=-x;
                    return x;
                }
                else
                {
                    char maxInt_plus[10]={2,1,4,7,4,8,3,6,4,7};
                    bool check=true;
                    for(int j=0; j<i;++j)
                    {
                        if( cifra[j]<maxInt_plus[j] )
                            check=false;
                        if(cifra[j]>maxInt_plus[j] && check )
                            return 0;
                        else x=x*10+cifra[j];
                    }
                    return x;
                }
            }

            if(verifyCharIsInt(s[i])==false && foundNumber)
            {
                exit=true;
                break;
            }

        }
        if(semn)
            x=-x;
        return x;
    }

};
*/

int main()
{
    Solution solutie;
    cout<<solutie.myAtoi("-2147483648");

    return 0;
}
