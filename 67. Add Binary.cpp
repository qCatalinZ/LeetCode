#define zero 48
#define one 49
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string output;
        int sizeA=a.size(),sizeB=b.size();
        int i;
        for(i=0;i<sizeA;++i)
            output=a[i]+output;
        a="";
        for(i=0;i<sizeB;++i)
            a=b[i]+a;
        b=a;
        a=output;
        output="";
        int carry=zero;
        int min=(sizeA>=sizeB)?sizeB:sizeA;
        int sum;
        for(i=0;i<min;++i)
        {   
            sum=(int)a[i]+(int)b[i]+carry;
            switch(sum)
            {
                case 144:
                    output="0"+output;
                    carry=zero;
                    break;
                case 145:
                    output="1"+output;
                    carry=zero;
                    break;
                case 146:
                    output="0"+output;
                    carry=one;
                    break;
                case 147:
                    output="1"+output;
                    carry=one;
                    break;
            }
        }
        string aux;
        if(sizeA>sizeB)
            aux=a;
        else
        {
            sizeA=sizeB;
            aux=b;
        }
        for(i=min;i<sizeA;++i)
        {
            sum=(int)aux[i]+carry;
            switch(sum)
            {
                case 96:
                    output="0"+output;
                    carry=zero;
                    break;
                case 97:
                    output="1"+output;
                    carry=zero;
                    break;
                case 98:
                    output="0"+output;
                    carry=one;
                    break;
            }
        }
        if(carry==one)
            output="1"+output;
        return output;   
    }
};