class Solution {
public:
    int lengthOfLastWord(const string &s) 
    {
        int size=s.size()-1;
        int length=0;
        while(1)
        {
            if(s[size]!=' ')
                break;
            else size--;
        }
        while(1)
        {
            if(s[size]==' ')
                break;
            length++;
            if(size==0)
                break;
            size--;
        }
        return length;
    }
};