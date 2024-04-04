class Solution {
public:
    int mySqrt(const int &x) 
    {
        if(x==0)
            return 0;
        long long power=1,p1;
        while(1)
        {
            p1=power+1;
            if(power*power<=x && p1*p1>x)
                break;
            power++;
        }
        return power;
    }
};