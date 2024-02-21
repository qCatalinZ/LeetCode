#include <iostream>
using namespace std;

/*
#define maxInt32bit 2147483647

int lungime(int aux)
{
    int l=0;
    while(aux)
    {
        l++;
        aux/=10;
    }
    return l;
}

class Solution
{
    public:

    int reverse(int x)
    {
        signed int aux=0;
        bool semn=false;
        if(x<0)
        {
            x=-x;
            semn=true;
        }

        while(x)
        {
            if(lungime(aux)==9)
            {
                if( aux%1000000000>2 )
                    return 0;
                if( aux%10000000>0)
            }
            aux=aux*10+x%10;
            x/=10;
        }

        if(semn)
            aux=-aux;
        return aux;
    }
};
*/

class Solution
{
    public:

    int reverse(int x)
    {
        if(x==-2147483648 || x==2147483647)
            return 0;

        bool semn=false;

        if(x<0)
        {
            semn=true;
            x=-x;
        }

        int cifra[10]={10,11,12,13,14,15,16,17,18,19};
        int i=0;    // lungime

        while(x)
        {
            cifra[i]=x%10;
         //   cout<<cifra[i]<<" ";
            x/=10;
            i++;
        }

        if(i<10)
        {
            for(int j=0; j<i;++j)
                x=x*10+cifra[j];
            if(semn)
                x=-x;
            return x;
        }

        if(i==10)
        {
            if(semn)
            {
                char maxInt_minus[10]={2,1,4,7,4,8,3,6,4,8};
                                   //  2,1,4,3,8,4,7,4,1,2
                bool check=true;
                for(int j=0; j<i;++j)
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

        return x;
    }
};

int main()
{
    //cout<<lungime(123)<<endl;
    Solution solutie;
    cout<<solutie.reverse(-1234);

    return 0;
}
