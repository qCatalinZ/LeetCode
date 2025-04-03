class Solution {
public:

    char digitToString(const int &n)
    {
        switch(n)
        {
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
        }
        return '0';
    }

    string numberToString(int n)
    {
        string str = "";
        while(n)
        {
            str = str + digitToString(n%10);
            n/=10;
        }

        string output = "";
        for(int i = str.size() - 1; i >= 0; --i)
        {
            output = output + str[i];
        }

        return output;
    }

    string RLE(const string &str)
    {
        int size = str.size();

        if(size == 1)
            return "1" + str;
        
        string output="";
        int times=1;
        for(int i = 0;i < size; ++i)
        {
            if(str[i] == str[i+1])
                times++;
            else
            {
                output = output + numberToString(times) + str[i];
                times = 1;
            }
        }

        return output;
    }

    string countAndSay(const int &n) 
    {
        if(n == 1)  return "1";
        return RLE(countAndSay(n-1));
    }
};