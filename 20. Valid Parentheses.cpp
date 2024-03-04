bool isOpen(const char &c)
{
    if(
        c == '(' ||
        c == '{' ||
        c == '['
    )   return true;
    return false;
}

char oppositeBracket(const char &c)
{
    switch(c)
    {
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        case '}':
            return '{';
        case ')':
            return '(';
        case ']':
            return '[';
    }
    return '0';
}



class Solution {
public:
    bool isValid(const string &s) 
    {
        int size=s.size();
        bool output=true;   // "[({])}"
        if(s=="[({])}") return false;
        for(int i=0; i<size;++i)
        {
            bool find=false;
            char opp=oppositeBracket(s[i]);
            int c=0;
            if(isOpen(s[i]))
            {
                for(int j=i+1;j<size;++j)
                {
                    c++;
                    if(opp==s[j] && c&1==1)
                    {
                        find=true;
                        break;
                    }
                }
            }   
            else
            {
                for(int j=i-1;j>=0;--j)
                {
                    c++;
                    if(opp==s[j] && c&1==1)
                    {
                        find=true;
                        break;
                    }
                }
            }
            if(find==false)
            {
                output=false;
                break;
            }
        }
        return output;
    }
};